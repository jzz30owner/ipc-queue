#include "MemWritter.h"

#include <cstdint>
#include <cstring>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <time.h>

#include "SharedState.h"


MemWritter::MemWritter() : buffer_id_(0), ptr_(nullptr), temp_pos_(nullptr)
{
}

MemWritter::~MemWritter() {
  if (buffer_id_) {
    shmdt(ptr_);
  }
}

bool MemWritter::allocateBuffer(size_t size) {
  uint64_t key = time(nullptr);
  buffer_id_ = shmget(key, size + sizeof(SharedState), IPC_CREAT | 0666);
  if (buffer_id_ == -1) {
    // TODO: add some logs
    return false;
  }
  ptr_ = shmat(buffer_id_, nullptr, 0);
  if (ptr_ == nullptr || *reinterpret_cast<int*>(ptr_) == -1) {
    // TODO: add some logs
    return false;
  }
  if (shmctl(buffer_id_, IPC_RMID, nullptr) == -1) {
    shmdt(ptr_);
    // TODO: add some logs
    return false;
  }
  state_ = reinterpret_cast<SharedState*>(ptr_);
  state_->channel_id = 1;
  state_->buffer_size = size;
  state_->pos = reinterpret_cast<uint8_t*>(ptr_) + sizeof(SharedState);
  return true;
}

int MemWritter::write(const void * data, size_t size) {
  if (!ptr_) {
    // TODO: add some logs
    return -1;
  }
  if (reinterpret_cast<uint8_t*>(state_->pos) + size >= state_->data + size) {
    state_->pos = state_->data;
  }
  memcpy(state_->pos, data, size);
}

void MemWritter::writeDone() {
  state_->pos = temp_pos_;
  // TODO: notify all consumers(maybe I will add some sem)
}

