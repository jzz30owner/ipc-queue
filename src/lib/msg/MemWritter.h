#pragma once

#include <cstdint>
#include <span>


#include "Message.h"


class MemWritter final {
public:
  MemWritter();

  ~MemWritter();

  bool allocateBuffer(size_t size);

  int getSharedBufferId() const;

  void * getPtr();


private:
  int buffer_id_;
  void * ptr_;

};

inline int MemWritter::getSharedBufferId() const { return buffer_id_; };

inline void * MemWritter::getPtr() { return ptr_; }
