cmake_minimum_required(VERSION 3.6)
project(lihai)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        src/base.h
        src/bisearch.h
        src/main.cpp
        src/option.h
        src/panic.h
        src/prime.cpp
        src/prime.h
        src/qsort.cpp
        src/qsort.h
        src/types.h)

add_executable(lihai ${SOURCE_FILES})