cmake_minimum_required(VERSION 3.6)
project(lihai)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        cpp/base.h
        cpp/bisearch.h
        cpp/main.cpp
        cpp/option.h
        cpp/prime.cpp
        cpp/prime.h
        cpp/qsort.cpp
        cpp/qsort.h
        cpp/types.h cpp/bitmap.h cpp/left_rotate.h)

add_executable(lihai ${SOURCE_FILES})
