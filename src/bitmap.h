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
    static const Value block_bit = sizeof(Block) * 8;
public:
    static const Value size = block_bit * N;

    void add(Value x) {
        blocks[index(x)] |= bit(x);
    }

    void remove(Value x) {
        blocks[index(x)] &= ~bit(x);
    }

    bool get(Value x) {
        auto i = index(x);
        auto block = blocks[i];
        auto b = bit(x);
        return (block & b) != 0;
    }
private:
    std::array<Block, N> blocks{};
    Value index(Value x) {
        Value i = x / block_bit;
        if (i > N-1) {
            throw std::out_of_range("out of bitmap range.");
        }
        return i;
    }

    Block bit(Value x) {
        Block bit = 1;
        return bit << (x % block_bit);
    }
};
