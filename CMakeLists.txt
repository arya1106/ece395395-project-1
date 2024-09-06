cmake_minimum_required(VERSION 3.12)
project(MyProject)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)

# Add your source files here
set(SOURCES
    hash_list.cpp
)

add_executable(MyProject ${SOURCES})