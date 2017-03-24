#include "qsort.h"
#include <cassert>

using Value = i32;


Value make_pivot(Value *arr, usize left, usize right) {
    using helper::swap;
    // 三值中分，确保 头 <= pivot <= 尾
    // 这里有交换整理的功能，所以不适合用 std::min_element 。
    usize mid = helper::median(left, right);

    Value &l = arr[left], &r = arr[right], &m = arr[mid];

    if (l > r) { swap(l, r); }
    if (l > m) { swap(l, m); }
    if (m > r) { swap(m, r); }

    assert(l <= m && m <= r);

    // 交换以后将 pivot 放到尾前一个位置。
    swap(m, arr[right - 1]);
    return arr[right - 1];
}


void sort(Value *arr, usize left, usize right) {
    using helper::swap;

    if (left == right) { return; } // 边界条件。
    // 将头尾和 pivot 按顺序排好，把 pivot 移动到 [right-1] 位置。
    Value pivot = make_pivot(arr, left, right);
    if (right - left < 3) { return; } // 边界条件，在这种情况下已经排好序了。
    // 处理边界条件，最好的方式还是在小数组的情况下用插入排序。
    // 但这里强行处理一下。

    // i, j 是交换指针，在数组上左右滑动，直到遇到符合交换条件的元素停止。
    // 滑动时用 ++i, --j 所以初始值不会停下。
    // 所以设为头和 [right-1] 也就是 pivot 位置。
    // [  1, 3, 6, 5, 9, 3, 0, 4,   8]
    //  头^               pivot^  尾^
    //   i^                   j^
    usize i = left, j = right - 1;
    for (;;) {

        while (arr[++i] < pivot) {}
        while (arr[--j] > pivot) {}
        // [  1, 3, 6, 5, 9, 3, 0, 4,   8]
        //    |    i^          j^  |    |
        //  头^               pivot^  尾^
        // 滑动停止，交换两个元素。


        if (i < j) {
            swap(arr[i], arr[j]);
        }
        else {
            // 如果交错了，说明没有可交换的了，滑过头了，就跳出循环。
            break;
            // 到最后 j 会指向头，因为头 <= pivot 所以会停下来，
            // i 往前滑最后会指向 pivot 自己。
            // 所以能确保停下来。
        }
    }
    // 将 pivot 放到 i 所在的位置。
    swap(arr[i], arr[right - 1]);


    // 开启递归过程。
    sort(arr, left, i - 1);
    sort(arr, i + 1, right);
}


void qsort(Value *arr, usize len) {
    sort(arr, 0, len - 1);
}
