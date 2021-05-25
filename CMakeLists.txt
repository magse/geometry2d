cmake_minimum_required(VERSION 3.10)

project(geometry2dtest VERSION 0.4)

set(INC_DIR include)
set(HEADER_FILES ${INC_DIR}/versioon.hpp ${INC_DIR}/config.hpp ${INC_DIR}/methematical.hpp ${INC_DIR}/vec2.hpp ${INC_DIR}/circle2.hpp ${INC_DIR}/line2.hpp ${INC_DIR}/ray2.hpp ${INC_DIR}/geometry2d.hpp)

#target_include_directories(geometry2dtest PRIVATE ${INC_DIR})

message(STATUS "geometry2d install directory: " ${CMAKE_INSTALL_INCLUDEDIR})

add_library(geometry2d INTERFACE)
#target_sources(geometry2d INTERFACE ${HEADER_FILES})
target_include_directories(geometry2d INTERFACE include/)

install(DIRECTORY include/ DESTINATION include/)

option(ENABLE_TESTING OFF)

if (ENABLE_TESTING)
    enable_testing()
    add_subdirectory("test")
    add_test(NAME test1 COMMAND geometry2dtest --version)
endif()
