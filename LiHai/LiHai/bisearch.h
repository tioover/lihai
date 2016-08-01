#pragma once
#include "types.h"
#include "option.h"


template <typename T>
Option<usize> bisearch(const T arr[], const usize length, const T value) {
	usize start = 0;
	usize end = length - 1;
	usize mid;
	while (start <= end) {
		mid = start + ((end - start) >> 1);
		if (value > arr[mid]) {
			start = mid + 1;
		}
		else if (value < arr[mid]) {
			end = mid - 1;
		}
		else {
			return Option<usize>(mid);
		}
	}
	return Option<usize>();
}