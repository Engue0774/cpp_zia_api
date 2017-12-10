cmake_minimum_required (VERSION 2.6)
project(LogEmail)

set(CMAKE_MACOSX_RPATH 1)

set (CMAKE_CXX_STANDARD 11)

include_directories (../../../src/)

add_library(LogEmail SHARED LogEmail.cpp)