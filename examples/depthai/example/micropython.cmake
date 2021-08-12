# Create an INTERFACE library for our C module.
add_library(depthai INTERFACE)

# Add our source files to the lib
target_sources(depthai INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/examplemodule.c
)

# Add the current directory as an include directory.
target_include_directories(depthai INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}
)

# Link our INTERFACE library to the usermod target.
target_link_libraries(usermod INTERFACE depthai)
