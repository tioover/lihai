#include <random>
#include "gtest/gtest.h"
#include "base.h"
#include "bitmap.h"


static const usize max = 0x1000;

TEST(data_structure, bitmap) {
    std::random_device rand;
    std::array<u32, max> arr;
    Bitmap<0x1000> map;
    for (usize i = 0; i < max; i++) {
        arr[i] = static_cast<u32>(rand()) % map.size;
    }
    auto begin = std::begin(arr), end = std::end(arr);
    std::sort(begin, end);
    end = std::unique(begin, end);
    auto mid = helper::iter_median(begin, end);
    std::for_each(begin, mid, [&](u32 x) { map.add(x); });
    std::for_each(begin, mid, [&](u32 x) { EXPECT_TRUE(map.get(x)) << x; });
    for (auto i = mid; i<end; i++) {
        EXPECT_FALSE(map.get(*i)) << *i;
    }
    EXPECT_ANY_THROW(map.get(map.size));
    EXPECT_ANY_THROW(map.get(map.size + 1));
    EXPECT_ANY_THROW(map.get(map.size + 42));
    for (usize i = 0; i < 10; i++) {
        map.remove(arr[i]);
        EXPECT_FALSE(map.get(arr[i]));
    }
}

