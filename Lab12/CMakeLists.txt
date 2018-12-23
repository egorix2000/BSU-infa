cmake_minimum_required(VERSION 3.12)
project(Lab)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lab main.cpp EmptyFileException.cpp EmptyFileException.h
	Exception.h Exception.cpp BinarySearchTree.h        
	FileException.cpp FileException.h FileManager.h
        FileNotFoundException.cpp FileNotFoundException.h Node.h
	NodeNotFoundException.h NodeNotFoundException.cpp Manager.h)