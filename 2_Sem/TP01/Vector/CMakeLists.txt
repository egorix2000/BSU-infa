cmake_minimum_required(VERSION 3.12)
project(Lab)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lab main.cpp)
add_subdirectory(Vector)
add_subdirectory(Vectorex)
set_target_properties(Vectorex PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(Lab Vector Vectorex)