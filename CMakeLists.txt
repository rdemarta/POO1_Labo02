cmake_minimum_required(VERSION 3.14)
project(POO1_Labo02)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wconversion -Wextra -pedantic")

add_executable(POO1_Labo02 main.cpp String.cpp String.h)