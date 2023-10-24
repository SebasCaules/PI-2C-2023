cmake_minimum_required(VERSION 3.26)
project(P05 C)


set(CMAKE_C_FLAGS "-Wall -pedantic -std=c99 -lm")
set(CMAKE_C_STANDARD 99)

add_executable(P05
        getnum.c
        Ej9.c)
