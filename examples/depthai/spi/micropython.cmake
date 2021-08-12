# Create an INTERFACE library for our C module.
add_library(depthai_spi INTERFACE)

# Add our source files to the lib
target_sources(depthai_spi INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/spi.cpp
    ${CMAKE_CURRENT_LIST_DIR}/depthai-spi-api/spi_api.cpp
    ${CMAKE_CURRENT_LIST_DIR}/depthai-spi-api/common/float16.c
    ${CMAKE_CURRENT_LIST_DIR}/depthai-spi-api/common/esp32_spi_impl.c
    ${CMAKE_CURRENT_LIST_DIR}/depthai-spi-api/depthai-shared/src/datatype/DatatypeEnum.cpp
    ${CMAKE_CURRENT_LIST_DIR}/depthai-spi-api/depthai-spi-library/spi_messaging.c
    ${CMAKE_CURRENT_LIST_DIR}/depthai-spi-api/depthai-spi-library/spi_protocol.c
)

# Add the current directory as an include directory.
target_include_directories(depthai_spi INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/depthai-spi-api/depthai-shared/include
    ${CMAKE_CURRENT_LIST_DIR}/depthai-spi-api/depthai-spi-library
    ${CMAKE_CURRENT_LIST_DIR}/depthai-spi-api/common
    ${CMAKE_CURRENT_LIST_DIR}
)

# Link our INTERFACE library to the usermod target.
target_link_libraries(usermod INTERFACE depthai_spi)
