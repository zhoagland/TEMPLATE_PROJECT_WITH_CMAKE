file(GLOB SOURCES "*.cpp")

target_sources(unit_tests PRIVATE 
    ${SOURCES}
)

target_include_directories(unit_tests PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}"
)

target_link_libraries(unit_tests PRIVATE 
    MODULE_NAME_REPLACE_ME
    MODULE_NAME_REPLACE_ME_test_headers
    gtest_main
)

