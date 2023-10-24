cmake_minimum_required(VERSION 3.26)
project(P02)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "-Wall -pedantic -std=c99 -lm")

add_executable( P02 getnum.c
        Ej11.c)