cmake_minimum_required(VERSION 3.26)
project(P03 C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "-Wall -pedantic -std=c99 -lm")

add_executable(P03
getnum.c
        Ej4_Taller.c
)


