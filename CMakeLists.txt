cmake_minimum_required(VERSION 3.16)
project(Dictionary)

set(CMAKE_CXX_STANDARD 17)
add_executable(Dictionary main.cpp IDictionary.hpp Dictionary.hpp Dictionary.inl INot_found_exception.hpp Not_found_exception.hpp)
