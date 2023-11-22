cmake_minimum_required(VERSION 3.26)
project(Heap C)

set(CMAKE_C_STANDARD 11)

add_executable(Heap Test.c
        Heap.h
        heap.c)
