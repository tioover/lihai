cmake_minimum_required(VERSION 3.6)
project(Lihai)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        cpp/base.h
        cpp/option.h
        cpp/prime.cpp
        cpp/prime.h
        cpp/qsort.cpp
        cpp/qsort.h
        cpp/types.h cpp/bitmap.h cpp/generic.h)

add_library(LihaiCpp ${SOURCE_FILES})

add_subdirectory(cpp/tests)
