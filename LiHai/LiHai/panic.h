#pragma once
#include <iostream>
#include <cstdlib>

#define PANIC(s) std::cerr << __FILE__ << __LINE__ << std::endl << s << std::endl, std::abort()
