cmake_minimum_required(VERSION 3.10)

# set the project name
#project(geometry2dtest VERSION 0.4)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(INC_DIR ${PROJECT_SOURCE_DIR}/include)
set(HEADER_FILES ${INC_DIR}/versioon.hpp ${INC_DIR}/config.hpp ${INC_DIR}/methematical.hpp ${INC_DIR}/vec2.hpp ${INC_DIR}/circle2.hpp ${INC_DIR}/line2.hpp ${INC_DIR}/ray2.hpp ${INC_DIR}/geometry2d.hpp)

# to make config.h reachable
configure_file("${PROJECT_SOURCE_DIR}/include/config.hpp.in" "${PROJECT_BINARY_DIR}/include/config.hpp")
include_directories("${PROJECT_BINARY_DIR}/include")

# add the executable
add_executable(geometry2dtest ${PROJECT_SOURCE_DIR}/test/geometry2dtest.cpp)

