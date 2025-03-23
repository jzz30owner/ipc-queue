#pragma once

#include <cstdint>
#include <span>


#include "Message.h"
#include "SharedState.h"


class MemWritter final {
public:
  MemWritter();

  ~MemWritter();

  bool allocateBuffer(size_t size);

  int getSharedBufferId() const;

  int write(const void * data, size_t size);

  void writeDone();

private:
  int buffer_id_;
  void * ptr_;
  SharedState * state_;
  void * temp_pos_;
};

inline int MemWritter::getSharedBufferId() const { return buffer_id_; };

