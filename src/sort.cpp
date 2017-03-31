#include "sort.h"
#include "heap.h"
#include <cassert>
// 使用模板，以及半开半闭区间，以及最简实现，请参考 generic.h 的 template_qsort
using Value = i32;


Value make_pivot(Value *arr, usize left, usize right) {
    using std::swap;
    // 三值中分，确保 头 <= pivot <= 尾
    // 这里有交换整理的功能，所以不适合用 std::min_element 。
    usize mid = helper::median(left, right);

    Value &l = arr[left], &r = arr[right], &m = arr[mid];

    if (l > r) { swap(l, r); }
    if (l > m) { swap(l, m); }
    if (m > r) { swap(m, r); }

    assert(l <= m && m <= r);

    // 交换以后将 pivot 交换到尾前一个位置。
    // 这里因为尾部所指的元素已经确保 >= pivot 了，已经符合快速排序的原理。
    // 因此排序的时候根本就不用管，把 pivot 放在了尾前就很好。
    swap(m, arr[right - 1]);
    return arr[right - 1];
}


void sort(Value *arr, usize left, usize right) {
    using std::swap;

    // 处理边界条件最好的方式还是在小数组的情况下用插入排序。
    // 但这里的代码为了学习，强行处理。

    // 边界条件
    // 只有一个元素的情况 (left == right)
    if (left == right) { return; }
    // 注意如果没有底下的处理的话要改成 if (left >= right) 这很重要！
    // 参见最后的函数最后的递归调用。

    // 将头尾和 pivot 按顺序排好，把 pivot 移动到 arr[right-1] 位置。
    Value pivot = make_pivot(arr, left, right);

    // 边界条件，在这种情况下已经排好序了。

    if (right - left < 3) { return; }

    // i, j 是交换指针，在数组上左右滑动，直到遇到符合交换条件的元素停止。
    // 滑动时用 ++i, --j 所以初始值不会停下。
    // 设为头和 [right-1] 也就是 pivot 位置。
    // [  1, 3, 6, 5, 9, 3, 0, 4,   8]
    //  头^               pivot^  尾^
    //   i^                   j^
    usize i = left, j = right - 1;
    for (;;) {


        // 到最后 j 会指向头，因为安排好了头 <= pivot 所以会停下来，
        // i 往前滑最后会指向尾部，尾部 >= pivot 也会停下来，所以不用设置特殊的停止条件。
        // 对于没有安排，直接选取 pivot 的情况，要根据 pivot 选取的位置加上防止滑过头的边界条件。

        // 比如说 pivot 放在头部，j 能自动停止，所以就对 i 设条件：
        // while (arr[++i] < pivot && i < right)
        while (arr[++i] < pivot) {}
        // 放在尾部的话自然就是 while (arr[--j] > pivot && j > left)
        while (arr[--j] > pivot) {}

        // [  1, 3, 6, 5, 9, 3, 0, 4,   8]
        //    |    i^          j^  |    |
        //  头^               pivot^  尾^
        // 滑动停止，i 和 j 分别指向比 pivot 大和小的元素，交换两个元素，
        // 注意和 pivot 相等也会停下做一次交换，但是因为前置的 ++i --j 的缘故不会卡住。

        if (i < j) {
            swap(arr[i], arr[j]);
            // 在别的语言中，这里可能要 i += 1; j -= 1 来滑过刚才交换的地方。
            // 否则会卡在和 pivot 相等的元素无法推进。
        } else {
            // 如果交错了，说明没有可交换的了，滑过头了，就跳出循环。
            break;
        }
    }
    // 将 pivot 放到 i 所在的位置。
    // 这里注意，要根据 pivot 的位置选取 i 和 j，因为到最后 i 会指向更大的数而 j 会指向更小的数，
    // 所以如果 pivot 放在开头那么就和 j 调换，放在结尾就和 i 调换。
    // 这个代码放在结尾，所以和 i 调换。
    // [  1, 3, 0, 3, 9, 5, 6, 4,   8]
    //    |       j^ i^        |    |
    //  头^               pivot^  尾^
    // [  1, 3, 0, 3, 4, 5, 6, 9,   8]
    //    |       j^ i^        |    |
    //  头^               pivot^  尾^
    swap(arr[i], arr[right - 1]);


    // 开启递归过程。
    // 因为这里不检查，所以两次调用都有可能造成 right + 1 == left
    // 这需要在开头判断 if (left >= right) return;
    sort(arr, left, i - 1);
    sort(arr, i + 1, right);

}


void quick_sort(Value *arr, usize len) {
    // 一个代理函数隐藏参数。
    // 区间的选择，对于快速排序来说比起 [start, end) 而言，[start, end] 更方便。
    sort(arr, 0, len - 1);
}


void heap_sort(Value *arr, usize len) {
    Heap heap;
    for (int i = 0; i < len; ++i) {
        heap.insert(arr[i]);
    }
    for (int i = 0; i < len; ++i) {
        arr[i] = heap.pop();
    }
}
