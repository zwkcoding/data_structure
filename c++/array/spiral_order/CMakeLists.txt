cmake_minimum_required(VERSION 3.0.0)
project(spiralOrder VERSION 0.1.0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main2.cpp)
add_executable(spiralOrder ${SOURCE_FILES})
