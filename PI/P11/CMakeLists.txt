cmake_minimum_required(VERSION 3.25)
project(P11 C)

set(CMAKE_C_FLAGS "-Wall -pedantic -std=c99 -lm -g -fsanitize=address")
set(CMAKE_C_STANDARD 99)

add_executable(P11
        Ej10/Ej10_Main.c
        Ej10/Ej10.c

)