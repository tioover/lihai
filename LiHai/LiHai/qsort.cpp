#include "qsort.h"
#include <cassert>
inline void swap(i32 &a, i32 &b) {
	i32 tmp = a;
	a = b;
	b = tmp;
}


void sort(i32 arr[], usize left, usize right) {
	usize i = left - 1, j = right;
	i32 pivot = arr[right];
	for (;;) {
		while (arr[++i] < pivot) {}
		while (arr[--j] > pivot && i < j) {}
		if (i < j) {
			swap(arr[i], arr[j]);
		}
		else {
			break;
		}
	}
	swap(arr[i], arr[right]);
	if (left < i) {
		sort(arr, left, i - 1);
	}
	if (i < right) {
		sort(arr, i + 1, right);
	}
}


void qsort(i32 arr[], usize len) {
	sort(arr, 0, len - 1);
}
