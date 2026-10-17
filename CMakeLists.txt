cmake_minimum_required(VERSION 4.3)
project(cpp-lox)

set(CMAKE_CXX_STANDARD 26)

add_executable(cpp-lox src/main.cpp
        src/error.cpp
        src/scanner.cpp
        include/error.h
        include/token.h
        include/scanner.h)
