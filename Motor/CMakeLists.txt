project(Motor)
cmake_minimum_required(VERSION 2.8)
file ( GLOB_RECURSE SRC *.?pp )
SET(CMAKE_CXX_FLAGS "-std=c++11")


add_library(IAMaker SHARED ${SRC})
