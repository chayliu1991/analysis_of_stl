cmake_minimum_required(VERSION 2.6)

project(stl)

if(NOT CMAKE_BUILD_TYPE)
    set (CMAKE_BUILD_TYPE "Release")
endif()

set (CXX_FLAGS
    -g
    -Wall
    -Werror
    -Wno-unused-parameter
    -std=c++11
    -march=native
    -rdynamic
)


set (CMAKE_CXX_FLAGS_DEBUG "-o0")
set (CMAKE_CXX_FLAGS_RELEASE "-o2 -DNODEBUG")
set (EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set (LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

string(REPLACE ";" " " CMAKE_CXX_FLAGS "${CXX_FLAGS}")

string(TOUPPER ${CMAKE_BUILD_TYPE} BUILD_TYPE)
message(STATUS "CXX_FLAGS = " ${CMAKE_CXX_FLAGS} " " ${CMAKE_CXX_FLAGS_${BUILD_TYPE}})

add_subdirectory(test)

