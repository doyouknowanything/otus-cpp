cmake_minimum_required(VERSION 3.12)

project(helloworld_cli VERSION ${PROJECT_VERSION})

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

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)