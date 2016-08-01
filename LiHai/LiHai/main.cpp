#include <iostream>
#include "base.h"
#include "bisearch.h"


void test_bisearch() {
	const usize max = 100;
	i32 a[max];
	for (usize i = 0; i < max; i++) {
		a[i] = i;
	}
	for (usize i = 0; i < max; i++) {
		if (bisearch<i32>(a, max, i).unwrap() != i) {
			PANIC("Test failure.");
		}
	}
}


int main() {
	using namespace std;
	cout
		<< "LiHai" << endl << "--------" << endl
		<< "Binary search test. ";
	test_bisearch();
	cout
		<< "DONE" << endl;
	getchar();
}