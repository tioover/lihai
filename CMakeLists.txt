cmake_minimum_required(VERSION 3.6)
project(Lihai)
add_subdirectory(lib/googletest)
set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        src/base.h
        src/option.h
        src/prime.cpp
        src/prime.h
        src/sort.cpp
        src/sort.h
        src/types.h src/bitmap.h src/generic.h src/heap.h src/heap.cpp src/graph.h)

add_library(LihaiCpp ${SOURCE_FILES})

add_subdirectory(tests)
