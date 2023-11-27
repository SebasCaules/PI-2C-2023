cmake_minimum_required(VERSION 3.18)
project(P11 C)

set(CMAKE_C_FLAGS "-Wall -pedantic -std=c99 -lm -g -fsanitize=address")
set(CMAKE_C_STANDARD 99)

add_executable(P11
        FizzBuzz.c
)
