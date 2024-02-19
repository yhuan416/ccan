cmake_minimum_required(VERSION 3.5)

project(configurator)

set(ccan_base_path ${CMAKE_CURRENT_SOURCE_DIR}/../..)

include(${ccan_base_path}/config.cmake)

set(target_path ${CMAKE_BINARY_DIR}/tools/configurator)

# configurator tool, output to tools/configurator
add_executable(configurator configurator.c)
set_target_properties(configurator PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${target_path}
)

# config.h
add_custom_target(ccan_config
    COMMAND configurator cc ${CCAN_CFLAGS} > ${ccan_base_path}/config.h
    DEPENDS configurator
    WORKING_DIRECTORY ${target_path}
)
