cmake_minimum_required(VERSION 3.5)
project(prob_200)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES 200_number_of_islands.cpp)
add_executable(prob_200 ${SOURCE_FILES})
