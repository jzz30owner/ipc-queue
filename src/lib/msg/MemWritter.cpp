#include "MemWritter.h"

#include <cstdint>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <time.h>


MemWritter::MemWritter() : buffer_id_(0), ptr_(nullptr)
{
}

MemWritter::~MemWritter() {
  if (buffer_id_) {
    shmdt(ptr_);
  }
}

bool MemWritter::allocateBuffer(size_t size) {
  uint64_t key = time(nullptr);
  buffer_id_ = shmget(key, size, IPC_CREAT | 0666);
  if (buffer_id_ == -1) {
    // TODO: add some logs
    return false;
  }
  ptr_ = shmat(buffer_id_, nullptr, 0);
  if (ptr_ == nullptr || *reinterpret_cast<int*>(ptr_) == -1) {
    return false;
  }
  if (shmctl(buffer_id_, IPC_RMID, nullptr) == -1) {
    shmdt(ptr_);
    return false;
  }
  return true;
}

