#pragma once

#include <cstdint>
#include <span>
#include <sys/mman.h>

#include "Message.h"


class MemWritter final {
public:
  MemWritter();

  ~MemWritter();

  int getSharedBufferId() const;

  int write(const uint8_t* data, size_t size);

private:
  int buffer_id_;

};

inline int MemWritter::getSharedBufferId() const { return buffer_id_; };

