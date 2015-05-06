project(Sample_Rubik2D)
cmake_minimum_required(VERSION 2.8)
file ( GLOB_RECURSE SRC *.?pp )
SET(CMAKE_CXX_FLAGS "-std=c++11")

add_executable(Sample_Rubik2D ${SRC})
