cmake_minimum_required(VERSION 4.3)
project(jlox)

set(CMAKE_CXX_STANDARD 26)

add_executable(jlox main.cpp
        error.cpp
        error.h)
