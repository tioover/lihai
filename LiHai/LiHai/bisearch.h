#pragma once
#include "types.h"
#include "option.h"


template <typename T>
Option<usize> bisearch(const T array[], const usize length, const T value) {
	usize start = 0;
	usize end = length - 1;
	usize mid;
	while (start <= end) {
		mid = (end - start >> 1) + start;
		if (value > array[mid]) {
			start = mid + 1;
		}
		else if (value < array[mid]) {
			end = mid - 1;
		}
		else {
			return Option<usize>(mid);
		}
	}
	return Option<usize>();
}