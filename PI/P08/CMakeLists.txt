cmake_minimum_required(VERSION 3.25)
project(P08 C)

set(CMAKE_C_FLAGS "-pedantic -Wall -std=c99 -fsanitize=address -g -lm")
set(CMAKE_C_STANDARD 99)

add_executable(P08
        random.c
        getnum.c
        Ej6.c
)
