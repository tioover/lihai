#include <iostream>
#include "base.h"
#include "bisearch.h"

int main() {
	const i32 a[] = { 0, 1, 2, 3, 4, 5, 6, 233 };
	const usize bisearch_result = bisearch<i32>(a, 8, 233).unwrap();
	std::cout << "LiHai" << std::endl << "--------" << std::endl
	          << "Binary search result: " << bisearch_result << std::endl;
	std::getchar();
}