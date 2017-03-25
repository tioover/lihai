#pragma once

#include "base.h"


template<typename Iter>
Option<Iter> bisearch(Iter start, Iter end, typename std::iterator_traits<Iter>::value_type value) {
    helper::assert_random_iterator<Iter>();

    Iter mid;

    // 传入的区间是 [start, end)，所以循环条件为 start < end
    // 如果是 [start, end] 的话，这里要写成 start <= end
    while (start < end) {
        mid = helper::median(start, end);

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
