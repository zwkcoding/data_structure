cmake_minimum_required(VERSION 3.5)
project(findEle)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main1.cpp)
add_executable(findEle ${SOURCE_FILES})
