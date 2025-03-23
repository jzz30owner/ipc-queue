#pragma once

#include <cstdint>

struct Message {
  Message() = delete;

  uint64_t msg_number;
  uint16_t msg_size;
  uint16_t msg_checksum;
  uint8_t reserved[16];
  uint8_t data[0];
};

