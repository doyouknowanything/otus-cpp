project(Task1Tests)
message(STATUS "building ${PROJECT_NAME} Binary")

file(GLOB sources ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB headers ${CMAKE_CURRENT_SOURCE_DIR}/*.h)

add_executable(${PROJECT_NAME} ${sources} ${headers})

gtest_add_tests(${PROJECT_NAME} "" AUTO)

target_link_libraries(${PROJECT_NAME}
    GTest::GTest
    VersionChecker
)