#pragma once

#include <cstdint>

struct SharedState {
  uint64_t channel_id;    // A q identificator
  uint64_t buffer_size;   // Size of a data buffer( excluding this state )
  void * pos;             // Current written data position
  uint8_t reserved[32];   // For some future purposes
  uint8_t data[0];        // Data buffer

  SharedState() = delete;
};

