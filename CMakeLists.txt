project(IAMaker)
cmake_minimum_required(VERSION 2.8)
aux_source_directory(. SRC_LIST)
SET(CMAKE_CXX_FLAGS "-std=c++11")


set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

INCLUDE_DIRECTORIES(".")

add_subdirectory(Motor)
add_subdirectory(Samples)
#add_subdirectory(Sample_Rubik2D)
