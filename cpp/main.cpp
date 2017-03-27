#include <iostream>
#include <cassert>
#include <array>
#include "base.h"
#include "bisearch.h"
#include "qsort.h"
#include "prime.h"
#include "bitmap.h"
namespace test {
    void quicksort() {
        const usize max = 1000000;
        std::srand((unsigned int) (time(NULL)));
        std::array<i32, max> arr;
        for (usize i = 0; i < max; i++) {
            arr[i] = std::rand();
        }
        qsort(arr.data(), max);;
        for (usize i = 0; i < max - 1; i++) {
            assert(arr[i] <= arr[i + 1] && arr[i] >= 0);
        }
    }


    void binary_search() {
        const usize max = 100000;
        using A = std::array<i32, max>;
        A arr;
        for (usize i = 0; i < max; i++) {
            arr[i] = static_cast<i32>(i);
        }
        auto begin = std::begin(arr);
        auto iter = begin;
        auto end = std::end(arr);
        i32 i = 0;
        for (auto iter = begin; iter != end; iter++, i++) {
            auto result = bisearch(begin, end, i).unwrap();
            assert(result == iter);
        }
    }
}

int main() {
    using namespace std;
    cout
            << "Binary search test. ";
    test::binary_search();
    cout
            << "DONE" << endl
            << "Quick sort test: ";
    test::quicksort();
    cout
            << "DONE" << endl;
    const u32 prime = 4263116;
    cout
            << prime << "st prime is: "
            << prime_n(prime) << endl;
    Bitmap map = Bitmap();
    map.add(42);
    map.add(4242);
    assert(!map.get(11));
    assert(map.get(42));
    assert(map.get(4242));
    assert(!map.get(4241));
    getchar();
    return 0;
}
