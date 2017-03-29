#pragma once

#include "types.h"
#include "base.h"

template<typename Iter>
void flip(Iter start, Iter end) {
    auto mid = helper::median(start, end);
    for (usize i=0; start+i < mid; i++) {
        std::swap(*(start+i), *(end-i-1));
    }
}

template<typename Iter>
void left_move(Iter start, Iter end, usize i) {
    // 参见《编程珠玑》，或者代数书。
    flip(start, start+i);
    flip(start+i, end);
    flip(start, end);
}
