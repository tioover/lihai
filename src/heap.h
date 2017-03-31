#pragma once

#include <array>
#include "types.h"

class Heap {
    // TODO: 模板化，异常，与或使用 vector 代替 array。
public:
    static const usize capacity = 0x10000;
    using Value = i32;

    void insert(Value x);

    Value pop();

    Value &elem(usize i) {
        // 1 base 的下标方便计算，避免浪费一个空间，可以考虑用宏代替。
        // 理论上编译器很容易优化掉。
        return array[i - 1];
    }

    std::array<Value, capacity> array{};
    usize end = 0;
};
