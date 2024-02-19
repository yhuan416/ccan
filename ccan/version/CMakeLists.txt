cmake_minimum_required(VERSION 3.5)

include(${CMAKE_CURRENT_SOURCE_DIR}/../ccan.cmake)

# version
add_library(version INTERFACE)

add_dependencies(version ccan_config_h)

target_include_directories(version INTERFACE ${CMAKE_CURRENT_SOURCE_DIR} ${ccan_base_path})
