# This top level cmakelists file basically orchastrates the different targets that we want.

#set cmake version
cmake_minimum_required(VERSION 3.28)

#set project name
project(PROJECT_NAME_REPLACE_ME
        VERSION 1.0
        DESCRIPTION "Project Description"
)

# Add Project assets
add_subdirectory(assets)

# Source code for all the libraries
add_subdirectory(src)

# Add docs package
add_subdirectory(docs)

# Add unit test package
if(BUILD_TESTING)
    enable_testing()
    add_subdirectory(unit_tests)
endif()