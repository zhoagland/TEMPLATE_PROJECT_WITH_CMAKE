# This cmakelists file defines the executable target settings.[[]]
# This file could be the top level cmakelists but since we also want to generate other targets such as tests and docs it is nested.

#set language settings
set(CMAKE_C_STANDARD            11)
set(CMAKE_C_STANDARD_REQUIRED   ON)
set(CMAKE_C_EXTENSIONS          OFF)
set(EXECUTABLE_NAME example_app)

# Since exec project we add the main file to the executable
add_executable(${EXECUTABLE_NAME} main.c)

# Add config files
add_subdirectory(config)
target_link_libraries(${EXECUTABLE_NAME}
    INTERFACE
    config
)

# Add any subdirectories that contain source code.
add_subdirectory(example_module)
# Link the modules to the exec
target_link_libraries(${EXECUTABLE_NAME}
    PRIVATE
    MODULE_NAME_REPLACE_ME
)

install(
    TARGETS ${EXECUTABLE_NAME}
    CONFIGURATIONS Release
    RUNTIME DESTINATION bin
    COMPONENT out_component
)