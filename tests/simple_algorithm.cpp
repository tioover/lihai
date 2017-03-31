#include <array>
#include <random>
#include "gtest/gtest.h"
#include "qsort.h"
#include "generic.h"
#include "bitmap.h"
#include "prime.h"

static const usize max = 100000;


TEST(algorithm, qsort) {
    std::random_device rand;
    std::array<i32, max> arr;
    for (usize i = 0; i < max; i++) {
        arr[i] = rand() % 0x1000;
    }
    quick_sort(&arr[0], arr.size());
    for (usize i = 0; i < max - 1; i++) {
        EXPECT_TRUE(arr[i] <= arr[i + 1]);
    }
}

TEST(algorithm, template_qsort) {
    std::random_device rand;
    std::array<i32, max> arr;
    for (usize i = 0; i < max; i++) {
        arr[i] = rand() % 0x1000;
    }
    template_qsort(ITER(arr));
    for (usize i = 0; i < max - 1; i++) {
        EXPECT_LE(arr[i], arr[i + 1]);
    }
}

TEST(algorithm, bisearch) {
    using A = std::array<i32, max>;
    A arr;
    for (usize i = 0; i < max; i++) {
        arr[i] = static_cast<i32>(i);
    }
    auto begin = std::begin(arr);
    auto end = std::end(arr);
    i32 i = 0;
    for (auto iter = begin; iter != end; iter++, i++) {
        auto result = bisearch(begin, end, i).unwrap();
        EXPECT_EQ(result, iter);
    }
}


TEST(algorithm, left_rotate) {
    std::string s{"abcdefghijklmn"};
    std::string t{"defghijklmnabc"};
    left_move(ITER(s), 3);
    EXPECT_EQ(s, t);
}


TEST(algorithm, prime_n) {
    const u32 n = 4263116, p = 72621257;
    EXPECT_EQ(prime_n(n), p);
}

