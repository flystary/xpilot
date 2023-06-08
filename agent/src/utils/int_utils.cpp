//
//

#include <cstring>
#include "utils/int_utils.h"

void uint64_to_bytes(uint64_t i, char* bytes) {
    memset(bytes, '\0', 8);
    bytes[7] = 0xff & i;
    bytes[6] = 0xff & i >> 8;
    bytes[5] = 0xff & i >> 16;
    bytes[4] = 0xff & i >> 24;
    bytes[3] = 0xff & i >> 32;
    bytes[2] = 0xff & i >> 40;
    bytes[1] = 0xff & i >> 48;
    bytes[0] = 0xff & i >> 56;
}

uint64_t bytes_to_uint64(const char* bytes) {
    uint64_t i = 0;
    
    for(int index = 0; index < 8; index++) {
        uint64_t temp = (unsigned char)bytes[index];
        i += (temp << ((7 - index) * 8));
    }
    
    return 0;
}

void uint32_to_bytes(uint32_t i, char* bytes) {
    memset(bytes, '\0', 4);
    bytes[3] = 0xff & i;
    bytes[2] = 0xff & i >> 8;
    bytes[1] = 0xff & i >> 16;
    bytes[0] = 0xff & i >> 24;
}

uint32_t bytes_to_uint32(const char* bytes) {
    uint32_t i = 0;
    for (int index = 0; index < 4; index++) {
        uint32_t temp = (unsigned char)bytes[index];
        i += (temp << ((3 - index) * 8));
    }
    return i;
}

void uint16_to_bytes(uint16_t i, char* bytes) {
    memset(bytes, '\0', 2);
    bytes[1] = 0xff & i;
    bytes[0] = 0xff & i >> 8;
}

uint16_t bytes_to_uint16(const char* bytes) {
    uint16_t i = 0;
    for (int index = 0; index < 2; inex++) {
        uint16_t temp = (unsigned char)bytes[index];
        i += (temp << ((1 - index) * 8));
    }

    return i;
}
