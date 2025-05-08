add_subdirectory(app)
add_subdirectory(libs)

if(BUILD_TESTING)
    add_subdirectory(tests)
endif()