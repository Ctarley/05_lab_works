cmake_minimum_required (VERSION 3.6)
project (LR)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/bin)

add_subdirectory (LR_2/Dynamic)
add_subdirectory (LR_2/Static)