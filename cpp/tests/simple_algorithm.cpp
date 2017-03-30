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

TEST(algorithm, bitmap) {
    std::random_device rand;
    std::array<u32, max> arr;
    Bitmap map = Bitmap();
    for (usize i = 0; i < max; i++) {
        arr[i] = static_cast<u32>(rand()) % BITMAP_SIZE;
    }
    auto begin = std::begin(arr), end = std::end(arr);
    std::sort(begin, end);
    end = std::unique(begin, end);
    auto mid = helper::iter_median(begin, end);
    std::for_each(begin, mid, [&](u32 x){ map.add(x); });
    std::for_each(begin, mid, [&](u32 x){ EXPECT_TRUE(map.get(x)) << x; });
    std::for_each(mid, end, [&](u32 x){ EXPECT_FALSE(map.get(x)) << x; } );
    EXPECT_ANY_THROW(map.get(BITMAP_SIZE));
    EXPECT_ANY_THROW(map.get(BITMAP_SIZE+1));
    EXPECT_ANY_THROW(map.get(BITMAP_SIZE+42));
    for (usize i = 0; i < 10; i++) {
        map.remove(arr[1]);
        EXPECT_FALSE(map.get(arr[1]));
    }
}


