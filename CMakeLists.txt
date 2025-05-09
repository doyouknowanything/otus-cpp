cmake_minimum_required(VERSION 3.12)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})

project(otus-cpp VERSION ${PROJECT_VERSION})

configure_file(version.h.in version.h)
set(VERSION_FILE ${CMAKE_CURRENT_BINARY_DIR})

if (BUILD_TESTING)
    enable_testing()
    find_package(GTest)
    add_definitions(-DBUILD_TESTING)
endif()

add_subdirectory(task1)

set(CPACK_PACKAGE_NAME helloworld)
set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT example@example.com)
include(CPack)