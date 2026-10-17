cmake_minimum_required(VERSION 4.3)
project(jlox)

set(CMAKE_CXX_STANDARD 26)

add_executable(jlox src/main.cpp
        src/error.cpp
        src/scanner.cpp
        include/error.h
        include/token.h
        include/scanner.h)
