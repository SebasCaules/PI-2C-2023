cmake_minimum_required(VERSION 3.25)
project(P10 C)

set(CMAKE_C_FLAGS "-Wall -pedantic -std=c99 -lm -g -fsanitize=address")
set(CMAKE_C_STANDARD 99)

add_executable(P10
        getnum.c
        random.c
        utillist.c
        Ej5.c
)
