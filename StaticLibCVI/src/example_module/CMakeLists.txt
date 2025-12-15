# This file is a template for adding additional source code to the exe. It is basically a static lib that gets linked in.

# Build the main static library. Only list source files here.
add_library(MODULE_NAME_REPLACE_ME STATIC
    "${CMAKE_CURRENT_SOURCE_DIR}/source_file.c"
)

# Add the required include paths for the MODULE_NAME_REPLACE_ME source file.
# The `PRIVATE` keyword means this include path is for internal use only.
target_include_directories(MODULE_NAME_REPLACE_ME PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}"
)

# This INTERFACE library holds the public header file.
# Any target that links to `MODULE_NAME_REPLACE_ME` will get this include path automatically.
add_library(MODULE_NAME_REPLACE_ME_public_headers INTERFACE)

# We explicitly list ONLY the public header in the PUBLIC_HEADER property.
set_target_properties(MODULE_NAME_REPLACE_ME_public_headers PROPERTIES
    PUBLIC_HEADER "${CMAKE_CURRENT_SOURCE_DIR}/source_header.h"
)

# This INTERFACE library holds the headers for unit testing purposes.
# contains both internal and external function declarations.
add_library(MODULE_NAME_REPLACE_ME_test_headers INTERFACE)
target_include_directories(MODULE_NAME_REPLACE_ME_test_headers INTERFACE
    "${CMAKE_CURRENT_SOURCE_DIR}"
)

# Link the static library to its public headers.
target_link_libraries(MODULE_NAME_REPLACE_ME PUBLIC 
    MODULE_NAME_REPLACE_ME_public_headers
)

# Set the public header for installation. This is the correct way to
# install headers linked via an INTERFACE library.
install(
    TARGETS MODULE_NAME_REPLACE_ME MODULE_NAME_REPLACE_ME_public_headers
    EXPORT MODULE_NAME_REPLACE_ME_export
    PUBLIC_HEADER
    ARCHIVE DESTINATION lib
)

# This is a key step: install the generated export file.
install(
    EXPORT MODULE_NAME_REPLACE_ME_export
    DESTINATION lib/cmake/MODULE_NAME_REPLACE_ME
    NAMESPACE dsa::
)
