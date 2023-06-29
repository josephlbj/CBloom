cmake_minimum_required(VERSION 3.16)
project(bloomc C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(bloomc
        bloom.c
        bloom.h
        main.c murmur.c murmur.h)
