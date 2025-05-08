project(VersionChecker)

message(STATUS "building ${PROJECT_NAME} Library")

file(GLOB headers ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
file(GLOB sources ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_library(${PROJECT_NAME} ${sources} ${headers})

target_include_directories(${PROJECT_NAME} PUBLIC ${VERSION_FILE})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)