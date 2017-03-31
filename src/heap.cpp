#include "heap.h"


void Heap::insert(Value x) {
    // 没写容量检测，日后可以考虑用 vector。
    usize i = ++end;
    for (; i > 1 && elem(i / 2) > x; i /= 2) {
        elem(i) = elem(i / 2);
    }
    elem(i) = x;
}


Heap::Value Heap::pop() {
    // 没写容量检测
    Value min = elem(1), last = elem(end--);
    usize i, child;

    // 对于左右两个节点，查找哪个更小，往上覆盖，重复这一步骤。
    for (i = 1; i * 2 <= end; i = child) {
        // 定位到左子节点。
        child = i * 2;

        // 对于 i * 2 == end 的情况下，二叉树已经不存在最右下的节点了，所以就不去测试比较了。
        if (child < end && elem(child) > elem(child + 1)) {
            // 右节点更小的情况下定位到右子节点。
            child += 1;
        }
        // 直到末尾元素比当前节点小（或相等），或者到了叶子结点。
        if (last > elem(child)) { elem(i) = elem(child); } else { break; }
    }
    elem(i) = last;
    return min;
}
