cmake_minimum_required(VERSION 3.12)

project(ip_filter VERSION ${PROJECT_VERSION})

message(STATUS "building ${PROJECT_NAME} Binary")

file(GLOB headers ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
file(GLOB sources ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_executable(${PROJECT_NAME} ${headers} ${sources})

set_target_properties(${PROJECT_NAME} PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)

target_compile_options(${PROJECT_NAME} PRIVATE
        -Wall -Wextra -pedantic -Werror
)

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)