#pragma once
#include <algorithm>
#include "types.h"
#include "base.h"

template<typename Iter>
void template_qsort(Iter start, Iter end) {
    // 注意和 qsort 版本的差异，不详细说明。
    if (start >= end-1) { return; } // 注意区间和其它差异
    Iter i = start, j = end;
    auto pivot = *start;
    for (;;) {
        while (*++i < pivot && i != end - 1) {}
        while (*--j > pivot) {}
        if (i < j) { std::swap(*i, *j); }
        else {
            std::swap(*start, *j);
            template_qsort(start, j); // 区间差异
            template_qsort(j+1, end);
            return;
        }
    }
}


template<typename Iter>
void flip(Iter start, Iter end) {
    auto mid = helper::iter_median(start, end);
    for (usize i = 0; start + i < mid; i++) {
        std::swap(*(start + i), *(end - i - 1));
    }
}

template<typename Iter>
void left_move(Iter start, Iter end, usize i) {
    // 参见《编程珠玑》，或者代数书。
    // 旋转你的手掌的步骤是，翻转你的左手，翻转你的右手，然后整个翻转两只手。
    flip(start, start + i);
    flip(start + i, end);
    flip(start, end);
}


template<typename Iter>
Option<Iter> bisearch(Iter start, Iter end, typename std::iterator_traits<Iter>::value_type value) {
    helper::assert_random_iterator<Iter>();

    Iter mid;

    // 传入的区间是 [start, end)，所以循环条件为 start < end
    // 如果是 [start, end] 的话，这里要写成 start <= end
    while (start < end) {
        mid = helper::iter_median(start, end);

        if (value > *mid) {
            start = mid + 1;
        } else if (value < *mid) {
            // 如果是 [start, end] 的话这里要改成 mid - 1
            end = mid;
        } else {
            return Option<Iter>(mid);
        }
    }
    return Option<Iter>();
}
