#pragma once

#include <cstdint>

struct SharedState {
  uint64_t channel_id;
  uint64_t buffer_size;
  void * pos;
  uint8_t reserved[32];
  uint8_t data[0];

  SharedState() = delete;
};

