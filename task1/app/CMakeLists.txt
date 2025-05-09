cmake_minimum_required(VERSION 3.12)

project(helloworld VERSION ${PROJECT_VERSION})

message(STATUS "building ${PROJECT_NAME} Binary")

add_executable(${PROJECT_NAME} main.cpp)

set_target_properties(${PROJECT_NAME} PROPERTIES
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED ON
)

target_link_libraries(${PROJECT_NAME} PUBLIC
    VersionChecker
)

target_compile_options(${PROJECT_NAME} PRIVATE
        -Wall -Wextra -pedantic -Werror
)

set(CPACK_PACKAGE_NAME ${PROJECT_NAME})
set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT example@example.com)
include(CPack)

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)