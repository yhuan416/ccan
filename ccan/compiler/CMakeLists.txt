cmake_minimum_required(VERSION 3.5)

include(${CMAKE_CURRENT_SOURCE_DIR}/../ccan.cmake)

# compiler
add_library(compiler INTERFACE)

add_dependencies(compiler ccan_config_h)

target_include_directories(compiler INTERFACE ${CMAKE_CURRENT_SOURCE_DIR} ${ccan_base_path})
