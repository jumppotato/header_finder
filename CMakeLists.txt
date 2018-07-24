cmake_minimum_required(VERSION 3.10)
project(HeaderFinder)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lboost_system -lboost_filesystem")

add_executable(HeaderFinder main.cpp file_reader.hpp)