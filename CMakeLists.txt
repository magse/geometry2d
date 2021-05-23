cmake_minimum_required(VERSION 3.10)

project(geometry2dtest VERSION 0.4)
add_subdirectory(test)

set(INC_DIR include)
set(HEADER_FILES ${INC_DIR}/versioon.hpp ${INC_DIR}/config.hpp ${INC_DIR}/methematical.hpp ${INC_DIR}/vec2.hpp ${INC_DIR}/circle2.hpp ${INC_DIR}/line2.hpp ${INC_DIR}/ray2.hpp ${INC_DIR}/geometry2d.hpp)

#add_executable(geometry2dtest geometry2dtest.cpp ${HEADER_FILES})
target_include_directories(geometry2dtest PRIVATE ${INC_DIR})

enable_testing()
add_test(NAME test1 COMMAND geometry2dtest --version)

