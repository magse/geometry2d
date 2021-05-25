
# Build
cmake_minimum_required(VERSION 3.12)

project(geometry2d VERSION 0.4.1 LANGUAGES CXX)

include(GNUInstallDirs)

add_library(${PROJECT_NAME} INTERFACE)

target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_14)

target_include_directories(
    ${PROJECT_NAME}
    INTERFACE
    $<BUILD_INTERFACE:${${PROJECT_NAME}_SOURCE_DIR}>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

# Test
find_package(Catch2 REQUIRED)
add_executable(test_geometry2d test/test_geometry2d.cpp)
target_link_libraries(test_geometry2d PRIVATE Catch2::Catch2)
target_include_directories(test_geometry2d PRIVATE ${PROJECT_SOURCE_DIR}/include)
include(CTest)
include(Catch)
catch_discover_tests(test_geometry2d)
enable_testing()

