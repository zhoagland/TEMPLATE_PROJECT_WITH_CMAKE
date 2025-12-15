set(MODULE_NAME config)

add_library(${MODULE_NAME} INTERFACE)

# Configure global headers
configure_file(config.h.in config.h)

target_include_directories(${MODULE_NAME}
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
)
