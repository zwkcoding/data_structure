cmake_minimum_required(VERSION 3.0.0)
project(uniquePath VERSION 0.1.0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(uniquePath ${SOURCE_FILES})
