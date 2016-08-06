#include <iostream>
#include <cassert>
#include <ctime>
#include <array>
#include "base.h"
#include "bisearch.h"
#include "qsort.h"
#include "prime.h"

namespace test
{
	void quicksort()
	{
		const usize max = 100000;
		std::srand((unsigned int)(time(NULL)));
		std::array<i32, max> arr;
		for (isize i = 0; i < max; i++)
		{
			arr[i] = std::rand();
		}
		qsort(arr.data(), max);
		;
		for (usize i = 0; i < max - 1; i++)
		{
			assert(arr[i] <= arr[i + 1] && arr[i] >= 0);
		}
	}


	void binary_search()
	{
		const usize max = 100;
		using A = std::array<i32, max>;
		A arr;
		for (usize i = 0; i < max; i++)
		{
			arr[i] = i;
		}
		auto begin = arr.begin();
		auto iter = begin;
		auto end = arr.end();
		i32 i = 0;
		while (iter != end)
		{
			auto result = bisearch(begin, end, i).unwrap();
			assert(result == iter);
			iter++;
			i++;
		}
	}
}

int main()
{
	using namespace std;
	cout
		<< "LiHai" << endl << "--------" << endl
		<< "Binary search test. ";
	test::binary_search();
	cout
		<< "DONE" << endl
		<< "Quick sort test: ";
	test::quicksort();
	cout
		<< "DONE" << endl;
	cout
		<< "4263116 prime is: "
		<< prime_n(4263116) << endl;
	getchar();
	return 0;
}