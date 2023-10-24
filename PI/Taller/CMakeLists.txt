cmake_minimum_required(VERSION 3.26)
project(Taller C)


set(CMAKE_C_FLAGS "-pedantic -Wall -std=c99 -fsanitize=address -g -lm")
set(CMAKE_C_STANDARD 11)

add_executable(Taller
        20-10/getnum.c
        20-10/Ej3.c
        20-10/random.c
)
