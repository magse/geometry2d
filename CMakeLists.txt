
# Following:
# https://ryandeangraham.medium.com/building-a-header-only-library-hello-world-f9dd05ac1066

# Build
cmake_minimum_required(VERSION 3.2)

project(geometry2d VERSION 0.4.1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(GNUInstallDirs)
#message("Supported features = ${CMAKE_CXX_COMPILE_FEATURES}")

add_library(${PROJECT_NAME} INTERFACE)
# TODO:  clean this up!
#target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_11)
#set_property(TARGET ${PROJECT_NAME} PROPERTY LINKER_LANGUAGE CXX)
#set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11)

#set_target_properties(${PROJECT_NAME}
#    PROPERTIES
#        CXX_STANDARD 11
#        CXX_STANDARD_REQUIRED YES
#        CXX_EXTENSIONS NO
#)


#target_include_directories(
#    ${PROJECT_NAME}
#    INTERFACE
#    $<BUILD_INTERFACE:${${PROJECT_NAME}_SOURCE_DIR}>
#    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
#)

# Tests (TODO: fix this. tests are broken)

add_executable(test_geometry2d test/test_geometry2d.cpp)

target_include_directories(test_geometry2d PRIVATE ${PROJECT_SOURCE_DIR}/include)

#include(CTest)

enable_testing()


# Install
install(TARGETS ${PROJECT_NAME}
        EXPORT ${PROJECT_NAME}_Targets
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

include(CMakePackageConfigHelpers)

write_basic_package_version_file("${PROJECT_NAME}ConfigVersion.cmake"
                                 VERSION ${PROJECT_VERSION}
                                 COMPATIBILITY SameMajorVersion)

if(NOT INCLUDE_INSTALL_DIR)
  set(INCLUDE_INSTALL_DIR include/geometry2d)
endif()

configure_package_config_file(
  "${PROJECT_SOURCE_DIR}/cmake/${PROJECT_NAME}Config.cmake.in"
  "${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
  INSTALL_DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/${PROJECT_NAME}/cmake
  PATH_VARS INCLUDE_INSTALL_DIR)
  
install(EXPORT ${PROJECT_NAME}_Targets
        FILE ${PROJECT_NAME}Targets.cmake
        NAMESPACE ${PROJECT_NAME}::
        DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/${PROJECT_NAME}/cmake)
	
install(FILES "${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
              "${PROJECT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
        DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/${PROJECT_NAME}/cmake)
	
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME})

