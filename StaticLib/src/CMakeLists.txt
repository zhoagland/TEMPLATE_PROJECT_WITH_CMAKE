# This cmakelists file defines the dll target settings.
# This file could be the top level cmakelists but since we also want to generate other targets such as tests and docs it is nested.

#set language settings
set(CMAKE_C_STANDARD            11)
set(CMAKE_C_STANDARD_REQUIRED   ON)
set(CMAKE_C_EXTENSIONS          OFF)

set(STATIC_LIB_NAME example_lib)

# Since exec project we add the main file to the executable
file(GLOB SOURCES "*.c" ".cpp")

add_library(${STATIC_LIB_NAME} STATIC)

target_sources(${STATIC_LIB_NAME} PRIVATE
    ${SOURCES}
)


# This INTERFACE library holds the public header file.
# Any target that links to `MODULE_NAME_REPLACE_ME` will get this include path automatically.
add_library(${STATIC_LIB_NAME}_public_headers INTERFACE)

# We explicitly list ONLY the public header in the PUBLIC_HEADER property.
set_target_properties(${STATIC_LIB_NAME}_public_headers PROPERTIES
    PUBLIC_HEADER "${CMAKE_CURRENT_SOURCE_DIR}/lib_example.h"
)

# This INTERFACE library holds the headers for unit testing purposes.
# contains both internal and external function declarations.
add_library(${STATIC_LIB_NAME}_test_headers INTERFACE)
target_include_directories(${STATIC_LIB_NAME}_test_headers INTERFACE
    "${CMAKE_CURRENT_SOURCE_DIR}"
)

# Link the static library to its public headers.
target_link_libraries(${STATIC_LIB_NAME} PUBLIC 
    ${STATIC_LIB_NAME}_public_headers
)

# Add config files
add_subdirectory(config)
target_link_libraries(${STATIC_LIB_NAME}
    INTERFACE
    config
)

# Add any subdirectories that contain source code.
add_subdirectory(example_module)
# Link the modules to the lib
target_link_libraries(${STATIC_LIB_NAME}
    PRIVATE
    MODULE_NAME_REPLACE_ME
)
    
# Set the public header for installation. This is the correct way to
# install headers linked via an INTERFACE library.
install(
    TARGETS ${STATIC_LIB_NAME} config
    EXPORT ${STATIC_LIB_NAME}_export 
    ARCHIVE DESTINATION lib
)

install(
    TARGETS ${STATIC_LIB_NAME}_public_headers
    PUBLIC_HEADER DESTINATION include
)

install(
    TARGETS ${STATIC_LIB_NAME}_public_headers
    EXPORT ${STATIC_LIB_NAME}_export
)

# This is a key step: install the generated export file.
install(
    EXPORT ${STATIC_LIB_NAME}_export
    DESTINATION lib/${STATIC_LIB_NAME}
    NAMESPACE ${STATIC_LIB_NAME}::
)