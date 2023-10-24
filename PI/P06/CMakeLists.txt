cmake_minimum_required(VERSION 3.26)
project(P06 C)

set(CMAKE_C_FLAGS "-Wall -pedantic -std=c99 -lm")
set(CMAKE_C_STANDARD 99)

add_executable(P06
        random.c
        Ej33.c
)
