find_program(DOXYGEN_PATH doxygen REQUIRED)

if(DOXYGEN_PATH_NOTFOUND)
  message(FATAL_ERROR "Doxygen is needed to build the documentation. Please install it on your system")

else()
    #message(STATUS "Doxygen found.")
    
    add_custom_target(documentation COMMAND ${DOXYGEN_PATH} ${CMAKE_CURRENT_LIST_DIR}/Doxyfile WORKING_DIRECTORY ${PROJECT_SOURCE_DIR})
     
endif()