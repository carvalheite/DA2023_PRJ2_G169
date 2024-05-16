cmake_minimum_required(VERSION 3.26)
project(DA2023_PRJ2_G169)

set(CMAKE_CXX_STANDARD 17)

add_executable(DA2023_PRJ2_G169 src/main.cpp
        src/FileReader.cpp
        src/backtraking.h
        src/Timer.h
        src/Timer.cpp)
