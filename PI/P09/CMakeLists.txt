cmake_minimum_required(VERSION 3.25)
project(P09 C)

set(CMAKE_C_FLAGS "-pedantic -Wall -std=c99 -fsanitize=address -g -lm")
set(CMAKE_C_STANDARD 99)

add_executable(P09
        Ej19.c
)
