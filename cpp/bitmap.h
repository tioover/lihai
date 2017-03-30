#pragma once

#include <stdexcept>
#include <array>
#include "types.h"

#define BITMAP_LEN 0x1000
#define BITMAP_BITNUM 64
#define BITMAP_SIZE BITMAP_LEN * BITMAP_BITNUM

class Bitmap {
    std::array<u64, BITMAP_LEN> data;

    u32 index(u32 x) {
        u32 i = x / BITMAP_BITNUM;
        if (i > BITMAP_LEN - 1) {
            throw std::out_of_range("out of bitmap range.");
        }
        return i;
    }

    u64 bit(u32 x) {
        u64 bit = 1;
        return bit << (x % BITMAP_BITNUM);
    }

public:
    void add(u32 x) {
        data[index(x)] ^= bit(x);
    }

    bool get(u32 x) {
        return (data[index(x)] & bit(x)) != 0;
    }
};
