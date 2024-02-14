cmake_minimum_required(VERSION 3.28)
project (threading)

SET (CMAKE_CXX_FLAGS "-std=c++20")
add_executable(mutex mutex.cpp)
add_executable(threadpool threadpool.cpp)
add_executable(atomic atomic.cpp)
add_executable(arrays arrays.cpp)
add_executable(referencing referencing.cpp)