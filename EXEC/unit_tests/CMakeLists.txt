# Library Unit test build guard.
option(BUILD_TESTING "Build unit tests and testing executables" ON)

# Allow fetching content.
include(FetchContent)

# Fetch gtest
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        v1.17.0
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

    
cmake_minimum_required(VERSION 3.20)

# Create project for the unit tests
project(unit_tests)
add_executable(unit_tests)

# add module sub dirs if they require unit tests.
add_subdirectory(example_module)

target_link_libraries(unit_tests PRIVATE 
    gtest_main
)

include(GoogleTest)
gtest_discover_tests(unit_tests)


