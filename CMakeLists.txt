cmake_minimum_required(VERSION 3.2)

project(ipc_q LANGUAGEES CXX)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(${CMAKE_SOURCE_DIR}/src/lib)
add_subdirectory(${CMAKE_SOURCE_DIR}/src/apps)

