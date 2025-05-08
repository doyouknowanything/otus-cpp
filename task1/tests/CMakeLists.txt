project(Task1Tests)
message(STATUS "building ${PROJECT_NAME} Binary")

file(GLOB sources ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_executable(${PROJECT_NAME} ${sources} )

target_link_libraries(${PROJECT_NAME}
    GTest::GTest
    VersionChecker
)

install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_SOURCE_DIR}/bin/tests)
