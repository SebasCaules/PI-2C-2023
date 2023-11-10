cmake_minimum_required(VERSION 3.26)
project(Taller C)


set(CMAKE_C_FLAGS "-pedantic -Wall -std=c99 -fsanitize=address -g -lm")
set(CMAKE_C_STANDARD 11)

add_executable(Taller
        27-10/getnum.c
        27-10/random.c
        10-11/queueADT/Main_queue.c
        10-11/queueADT/queueADT.h
        10-11/queueADT/queueADT.c
        10-11/diccioADT/diccioADT.c
        10-11/diccioADT/Main_diccio.c
        10-11/diccioADT/diccioADT.h
)
