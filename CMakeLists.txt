cmake_minimum_required(VERSION 3.10)

project(raytracingweekend VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(include)

file(GLOB_RECURSE SOURCE_FILES src/*.cpp include/*.hpp)

add_executable(output ${SOURCE_FILES})