cmake_minimum_required(VERSION 3.23)
project(high_performance_computing C)

set(CMAKE_C_STANDARD 99)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(high_performance_computing main.c lab-sheet-01/timing_of_loops.c lab-sheet-01/timing_of_loops.h lab-sheet-02/openmp_intro.h)
