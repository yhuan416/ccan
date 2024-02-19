cmake_minimum_required(VERSION 3.5)

include(${CMAKE_CURRENT_SOURCE_DIR}/../ccan.cmake)

# ptrint
add_library(ptrint INTERFACE)

add_dependencies(ptrint ccan_config_h)

target_link_directories(ptrint INTERFACE compiler build_assert)

target_include_directories(ptrint INTERFACE ${CMAKE_CURRENT_SOURCE_DIR} ${ccan_base_path})
