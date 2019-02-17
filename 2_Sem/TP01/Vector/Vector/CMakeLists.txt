cmake_minimum_required(VERSION 3.12)
PROJECT(Vector)

ADD_LIBRARY(Vector SHARED Vector.h VectorException.cpp VectorException.h VectorOutOfRangeException.cpp
        VectorOutOfRangeException.h VectorPopException.cpp VectorPopException.h)