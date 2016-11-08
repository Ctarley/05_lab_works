cmake_minimum_required (VERSION 3.6)
project (lr2_static)

add_compile_options(-std=c++11)

SET(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
SET(BUILD_SHARED_LIBRARIES OFF)
SET(CMAKE_EXE_LINKER_FLAGS "-static")

add_library(node STATIC Node.cpp)
add_executable(lr2_static Source.cpp)
target_link_libraries(lr2_static node)