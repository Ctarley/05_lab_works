cmake_minimum_required (VERSION 3.5)
project (lr2_dynamic)

add_compile_options(-std=c++11)
SET(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
SET(BUILD_SHARED_LIBRARIES OFF)
SET(CMAKE_EXE_LINKER_FLAGS "-static")
add_executable(lr2_dynamic Source.cpp)
 
