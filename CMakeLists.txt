project(IAMaker)
cmake_minimum_required(VERSION 2.8)
aux_source_directory(. SRC_LIST)
SET(CMAKE_CXX_FLAGS "-std=c++11")

file ( GLOB_RECURSE SRC *.?pp )
add_library(IAMaker SHARED ${SRC})

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
include_directories ( "." )

add_subdirectory(Sample_Rubik2D)
