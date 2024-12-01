cmake_minimum_required(VERSION 3.29)
project(matrixcpp)

set(CMAKE_CXX_STANDARD 11)

include_directories("${CMAKE_SOURCE_DIR}/include")

add_library(matrixcpp STATIC src/matrixcpp.cpp)

