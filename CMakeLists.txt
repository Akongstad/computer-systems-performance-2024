cmake_minimum_required(VERSION 3.28)
project(computer_systems_performance_2024 C)

set(CMAKE_C_STANDARD 11)

add_executable(computer_systems_performance_2024
        02-multithreading-examples/C/atomic.c
        02-multithreading-examples/C/mutex.c
        03-core-affinity/code-examples3/core-affinity.c
        03-core-affinity/code-examples3/core-affinity2.c
        03-core-affinity/code-examples3/no-affinity.cpp
        03-core-affinity/code-examples3/affinityperformanceexample.cpp
        03-core-affinity/code-examples3/affinity.cpp
        03-core-affinity/code-examples3/affinity.cpp
        03-core-affinity/code-examples3/affinity.cpp)
