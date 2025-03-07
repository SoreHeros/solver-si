cmake_minimum_required(VERSION 3.26)
project(solver_si C)

set(CMAKE_C_STANDARD 23)

add_executable(solver_si main.c
        solver.c
        solver.h
        lists.c
        lists.h)
