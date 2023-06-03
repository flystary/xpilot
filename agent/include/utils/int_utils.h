//


#ifndef INT_UTILS_H
#define INT_UTILS_H

#include <cstdint>

void uint64_to_bytes(uint64_t i, char *bytes);

uint64_t bytes_to_uint64(const char *bytes);

void uint32_to_bytes(uint32_t i, char *bytes);

uint32_t bytes_to_uint32(const char *bytes);

void uint16_to_bytes(uint16_t i, char *bytes);

uint16_t bytes_to_uint16(const char *bytes);

#endif
