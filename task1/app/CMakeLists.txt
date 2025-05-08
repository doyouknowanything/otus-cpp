cmake_minimum_required(VERSION 3.12)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})

project(helloworld VERSION ${PROJECT_VESRION})

#configure_file(version.h.in version.h)

add_executable(helloworld_cli main.cpp)

set_target_properties(helloworld_cli PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)

target_link_libraries(helloworld_cli PRIVATE
    helloworld
    VersionChecker
)

#if(BUILD_TESTING)
#    add_executable(test_version test_version.cpp)
#
#    set_target_properties(test_version PROPERTIES
#        CXX_STANDARD 14
#        CXX_STANDARD_REQUIRED ON
#    )
#
#    set_target_properties(test_version PROPERTIES
#        COMPILE_DEFINITIONS
##        INCLUDE_DIRECTORIES
 #   )

#    target_link_libraries(test_version
#        GTest::GTest
#        helloworld
#    )
#endif()

if (MSVC)
    target_compile_options(helloworld_cli PRIVATE
        /W4
    )
    if(BUILD_TESTING)
        target_compile_options(test_version PRIVATE
            /W4
        )
    endif()
else ()
    target_compile_options(helloworld_cli PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
#    if(BUILD_TESTING)
#        target_compile_options(test_version PRIVATE
#            -Wall -Wextra -pedantic -Werror
#        )
#    endif()
endif()

install(TARGETS helloworld_cli RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT example@example.com)
include(CPack)

if(BUILD_TESTING)
    add_test(test_version test_version)
endif()
