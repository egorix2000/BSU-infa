cmake_minimum_required(VERSION 3.12)
project(Lab)

set(CMAKE_CXX_STANDARD 14)

if (APPLE)
    add_definitions(-DGTEST_USE_OWN_TR1_TUPLE)
    add_definitions(-D__GLIBCXX__)
endif (APPLE)

add_subdirectory(googletest)
include_directories(googletest/googletest/include)

add_executable(Lab Node.h Stack.h tests.cpp findValueOfExpression.h)

target_link_libraries(Lab gtest gtest_main)