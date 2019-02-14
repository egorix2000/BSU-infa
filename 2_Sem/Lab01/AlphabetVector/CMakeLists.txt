cmake_minimum_required(VERSION 3.12)
project(Lab)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lab main.cpp
        Vector/Vector.h Vector/VectorException.cpp Vector/VectorException.h
        Vector/VectorOutOfRangeException.cpp Vector/VectorOutOfRangeException.h
        Vector/VectorPopException.cpp Vector/VectorPopException.h
        CharVectorManager.cpp CharVectorManager.h Vector/VectorIterator.h)