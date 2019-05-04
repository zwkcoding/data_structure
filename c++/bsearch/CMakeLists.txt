cmake_minimum_required(VERSION 3.5)
project(bSearch)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES bsearch_varients_test.cc)
project(bSearch)
add_executable(bSearch ${SOURCE_FILES})
