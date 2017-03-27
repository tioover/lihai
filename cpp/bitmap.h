#pragma once
#include <stdexcept>
#include "types.h"
#define BITMAP_MAX 0x1000

class Bitmap {
    u64 data[BITMAP_MAX] = {};
    u32 index(u32 x) {
        u32 i = x / 64;
        if (i > BITMAP_MAX-1) {
            throw std::out_of_range("out of bitmap range.");
        }
        return x / 64;
    }
    u64 bit(u32 x) {
        u64 bit = 1;
        return bit << x;
    }
public:
    void add(u32 x) {
        data[index(x)] ^= bit(x);
    }
    bool get(u32 x) {
        return (data[index(x)] & bit(x)) != 0;
    }
};
