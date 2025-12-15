# This cmakelists file defines the dll target settings.
# This file could be the top level cmakelists but since we also want to generate other targets such as tests and docs it is nested.

#set language settings
set(CMAKE_C_STANDARD            11)
set(CMAKE_C_STANDARD_REQUIRED   ON)
set(CMAKE_C_EXTENSIONS          OFF)

set(DYNAMIC_LIB_NAME example_dll)

# Since exec project we add the main file to the executable
file(GLOB SOURCES "*.c" ".cpp")
add_library(${DYNAMIC_LIB_NAME} SHARED)
target_sources(${DYNAMIC_LIB_NAME} PRIVATE
    ${SOURCES}
)

add_definitions(-D_EXAMPLE_DLL_EXPORTS_)

target_include_directories( ${DYNAMIC_LIB_NAME} PRIVATE
${CMAKE_CURRENT_SOURCE_DIR}
)


# Add config files
add_subdirectory(config)
target_link_libraries(${DYNAMIC_LIB_NAME}
    INTERFACE
    config
)

# Add any subdirectories that contain source code.
add_subdirectory(example_module)
# Link the modules to the exec
target_link_libraries(${DYNAMIC_LIB_NAME}
    PRIVATE
    MODULE_NAME_REPLACE_ME
)

#install directive adds the exe to the bin folder in the build dir.
install(TARGETS ${DYNAMIC_LIB_NAME} 
    CONFIGURATIONS Release
    DESTINATION bin 
    COMPONENT out_component)