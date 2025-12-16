# This file is a template for adding additional source code to the exe. It is basically a static lib that gets linked in.
set(MODULE_NAME MODULE_NAME_REPLACE_ME)

# Build the main static library. Only list source files here.
add_library(${MODULE_NAME} STATIC
    "${CMAKE_CURRENT_SOURCE_DIR}/source_file.c"
)

# Add the required include paths for the ${MODULE_NAME} source file.
# The `PRIVATE` keyword means this include path is for internal use only.
target_include_directories(${MODULE_NAME} PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}"
)

# This INTERFACE library holds the public header file.
# Any target that links to `MODULE_NAME_REPLACE_ME` will get this include path automatically.
add_library(${MODULE_NAME}_public_headers INTERFACE)

# We explicitly list ONLY the public header in the PUBLIC_HEADER property.
set_target_properties(${MODULE_NAME}_public_headers PROPERTIES
    PUBLIC_HEADER "${CMAKE_CURRENT_SOURCE_DIR}/source_header.h"
)

# This INTERFACE library holds the headers for unit testing purposes.
# contains both internal and external function declarations.
add_library(${MODULE_NAME}_test_headers INTERFACE)
target_include_directories(${MODULE_NAME}_test_headers INTERFACE
    "${CMAKE_CURRENT_SOURCE_DIR}"
)

# Link the static library to its public headers.
target_link_libraries(${MODULE_NAME} PUBLIC 
    ${MODULE_NAME}_public_headers
)

# Set the public header for installation. This is the correct way to
# install headers linked via an INTERFACE library.
install(
    TARGETS ${MODULE_NAME} 
    EXPORT ${MODULE_NAME}_export
    ARCHIVE DESTINATION lib
)

install(
    TARGETS ${MODULE_NAME}_public_headers
    PUBLIC_HEADER DESTINATION include
)

install(
    TARGETS ${MODULE_NAME}_public_headers
    EXPORT ${MODULE_NAME}_export
)

# This is a key step: install the generated export file.
install(
    EXPORT ${MODULE_NAME}_export
    DESTINATION lib/${MODULE_NAME}
    NAMESPACE ${MODULE_NAME}::
)
