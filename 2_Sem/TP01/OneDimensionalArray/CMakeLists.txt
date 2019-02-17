cmake_minimum_required(VERSION 3.12)
project(Lab)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lab main.cpp)
add_subdirectory(SinglyLinkedList)
add_subdirectory(Array)
set_target_properties(SinglyLinkedList Array PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(Lab SinglyLinkedList Array)