#pragma once
#include "types.h"
#include "panic.h"
#include "option.h"

#include <type_traits>
#include <iterator>
template <typename Iter>
inline void assert_random_iterator() {
	static_assert(
		std::is_same<
			typename std::iterator_traits<Iter>::iterator_category,
			std::random_access_iterator_tag
		>::value, "迭代器必须是随机的。");
}

template <typename T>
inline T median(T a, T b)
{
	return a + ((b - a) >> 1);
}