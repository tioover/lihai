#pragma once

#include <stdexcept>
#include <array>
#include "types.h"

template <unsigned int N>
class Bitmap {
public:
    using Value = u32;
private:
    using Block = u64;
    static constexpr Value block_bit = sizeof(Block) * 8;
public:
    static constexpr Value size = block_bit * N;

    void add(u32 x) {
        data[index(x)] |= bit(x);
    }

    void remove(u32 x) {
        data[index(x)] &= ~bit(x);
    }

    bool get(u32 x) {
        auto i = index(x);
        auto block = data[i];
        auto b = bit(x);
        return (block & b) != 0;
    }
private:
    std::array<Block, N> data{};
    Value index(Value x) {
        Value i = x / block_bit;
        if (i > N-1) {
            throw std::out_of_range("out of bitmap range.");
        }
        return i;
    }

    u64 bit(u32 x) {
        u64 bit = 1;
        return bit << (x % block_bit);
    }
};
