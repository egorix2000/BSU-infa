cmake_minimum_required(VERSION 3.12)
project(Lab)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lab main.cpp Vector.h VectorException.cpp VectorException.h VectorOutOfRangeException.cpp VectorOutOfRangeException.h VectorPopException.cpp VectorPopException.h)