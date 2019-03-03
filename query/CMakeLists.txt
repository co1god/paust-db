cmake_minimum_required(VERSION 3.13)
project(query C CXX)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

set(WITH_TESTS ON CACHE BOOL "")

find_package(Boost REQUIRED)
find_package(OpenFST REQUIRED)

if (WITH_TESTS)
    find_package(GTest CONFIG)
endif ()

add_subdirectory(cc)