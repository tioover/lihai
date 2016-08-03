#include <iostream>
#include <cassert>
#include <ctime>
#include "base.h"
#include "bisearch.h"
#include "qsort.h"


void test_qsort() {
	const usize max = 10000;
	std::srand((unsigned int)(time(NULL)));
	i32 arr[max];
	for (isize i = 0; i < max; i++) {
		arr[i] = std::rand();
	}
	qsort(arr, max);
	for (usize i = 0; i < max-1; i++) {
		assert(arr[i] <= arr[i + 1]);
	}
}


void test_bisearch() {
	const usize max = 100;
	i32 a[max];
	for (usize i = 0; i < max; i++) {
		a[i] = i;
	}
	for (usize i = 0; i < max; i++) {
		assert(bisearch<i32>(a, max, i).unwrap() == i);
	}
}


int main() {
	using namespace std;
	cout
		<< "LiHai" << endl << "--------" << endl
		<< "Binary search test. ";
	test_bisearch();
	cout
		<< "DONE" << endl
		<< "Quick sort test: ";
	test_qsort();
	cout
		<< "DONE" << endl;
	getchar();
}