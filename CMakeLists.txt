cmake_minimum_required(VERSION 3.28)
project(benchmark C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

add_executable(benchmark main.c matrix.c)
