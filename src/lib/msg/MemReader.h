#pragma once

#include <cstdint>
#include <span>
#include <sys/mman.h>

#include "Message.h"


class MemReader final {
public:
  MemReader(int shmem_id);

  ~MemReader();

  size_t copyRead(const uint8_t * out, size_t size);

  size_t zcRead(Message ** msg);
  bool zcReadDone(const Message * msg);

private:
  int buffer_id_;

};

