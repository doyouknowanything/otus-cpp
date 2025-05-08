cmake_minimum_required(VERSION 3.12)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})

project(otus-cpp)

option(BUILD_TESTING "Whether to build tests" ON)
configure_file(version.h.in version.h)
SET(VERSION_FILE ${CMAKE_CURRENT_BINARY_DIR}/version.h)

if (BUILD_TESTING)
    enable_testing()
    find_package(GTest)
    add_definitions(-DBUILD_TESTING)
endif()

add_subdirectory(task1)