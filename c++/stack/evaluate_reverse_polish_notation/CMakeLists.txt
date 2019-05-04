cmake_minimum_required(VERSION 3.0.0)
project(evalRPN VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(evalRPN main.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
