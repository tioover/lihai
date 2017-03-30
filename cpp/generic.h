#pragma once

#include <algorithm>
#include "types.h"
#include "base.h"

template<typename Iter>
void template_qsort(Iter begin, Iter end) {
    // 注意和 qsort.h 版本的差异，不详细说明。
    if (begin >= end - 1) { return; } // 注意区间和其它差异
    Iter i = begin, j = end;
    auto pivot = *begin;
    for (;;) {
        while (*++i < pivot && i != end - 1) {}
        while (*--j > pivot) {}
        if (i < j) { std::swap(*i, *j); }
        else {
            std::swap(*begin, *j);
            template_qsort(begin, j); // 区间差异
            template_qsort(j + 1, end);
            return;
        }
    }
}


template<typename Iter>
static void flip(Iter begin, Iter end) {
    auto mid = helper::iter_median(begin, end);
    for (usize i = 0; begin + i < mid; i++) {
        std::swap(*(begin + i), *(end - i - 1));
    }
}

template<typename Iter>
void left_move(Iter begin, Iter end, usize i) {
    // 参见《编程珠玑》，或者代数书。
    // 旋转你的手掌的步骤是，翻转你的左手，翻转你的右手，然后整个翻转两只手。
    flip(begin, begin + i);
    flip(begin + i, end);
    flip(begin, end);
}


template<typename Iter>
Option<Iter> bisearch(Iter begin, Iter end, typename std::iterator_traits<Iter>::value_type value) {
    helper::assert_random_iterator<Iter>();

    Iter mid;

    // 传入的区间是 [begin, end)，所以循环条件为 begin < end
    // 如果是 [begin, end] 的话，这里要写成 begin <= end
    while (begin < end) {
        mid = helper::iter_median(begin, end);

        if (value > *mid) {
            begin = mid + 1;
        } else if (value < *mid) {
            // 如果是 [begin, end] 的话这里要改成 mid - 1
            end = mid;
        } else {
            return Option<Iter>(mid);
        }
    }
    return Option<Iter>();
}
