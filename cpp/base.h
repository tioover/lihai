﻿#pragma once

#include <type_traits>
#include <iterator>
#include "types.h"
#include "option.h"


#define ITER(x) std::begin(x), std::end(x)

namespace helper {
    template<typename Iter>
    inline void assert_random_iterator() {
        static_assert(
                std::is_same<
                        typename std::iterator_traits<Iter>::iterator_category,
                        std::random_access_iterator_tag
                >::value, "The iterator must random access.");
    }

    template<typename T>
    inline T median(T a, T b) {
        // 显然这里是为了避免溢出。
        return a + (b - a) / 2;
    }

    template<typename T>
    inline void swap(T &a, T &b) {
        T t = a;
        a = b;
        b = t;
    }
}