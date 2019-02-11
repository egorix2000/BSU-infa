cmake_minimum_required(VERSION 3.12)
project(Lab)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lab main.cpp FileLib.h FileLib.cpp Node.h Polynomial.h Stack.h Vector.h)