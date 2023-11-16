cmake_minimum_required(VERSION 3.25)
project(P11 C)

set(CMAKE_C_FLAGS "-Wall -pedantic -std=c99 -lm -g -fsanitize=address")
set(CMAKE_C_STANDARD 99)

add_executable(P11
        Ej13/Ej13_Main.c
        Ej13/Ej13.c
        Ej14/Ej14_Main.c
        Ej14/Ej14.c
        Ej14/Ej14.h


)