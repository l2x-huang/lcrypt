# for `FetchContent'
cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

set(PROJ lcrypt)
project(${PROJ} VERSION 0.1.0)

# Point CMake at any custom modules we may ship
list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

#==========================================================================================
# Set C/C++ compiler
#==========================================================================================
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (CMAKE_BUILD_TYPE MATCHES "Debug" OR CMAKE_BUILD_TYPE EQUAL "None" OR NOT CMAKE_BUILD_TYPE)
    add_definitions(-DDebug)
endif()

# info
message(STATUS "PROJECT_NAME: ${PROJECT_NAME}")
message(STATUS "CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")
message(STATUS "C: ${CMAKE_C_COMPILER}")
message(STATUS "C++: ${CMAKE_CXX_COMPILER}")

#==========================================================================================
# Set Output
#==========================================================================================
message(STATUS "${CMAKE_BINARY_DIR}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/out/lib)

#===========================================================================================
# Add build options
#===========================================================================================
option(BUILD_TESTS "Build and run library tests" OFF)
#
# c++ package manager
include (CPM)
include (ccache)

# app
add_subdirectory(src)

# test
if(${BUILD_TESTS})
    enable_testing()
    add_subdirectory(tests)
endif()

# install
install(TARGETS ${CMAKE_PROJECT_NAME}
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib)

# pack
include(InstallRequiredSystemLibraries)
if (CMAKE_HOST_WIN32)
  set(CPACK_GENERATOR NSIS)
  set(CPACK_NSIS_MODIFY_PATH ON)
else ()
  set(CPACK_GENERATOR ZIP)
endif()

set(CPACK_PACKAGE_NAME ${PROJECT_NAME})
set(CPACK_PACKAGE_VENDOR "l2x")
set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})
# set(CPACK_PACKAGE_FILE_NAME)

include(CPack)
