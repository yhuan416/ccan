cmake_minimum_required(VERSION 3.5)

include(${CMAKE_CURRENT_SOURCE_DIR}/../ccan.cmake)

# build_assert
add_library(build_assert INTERFACE)

add_dependencies(build_assert ccan_config_h)

target_include_directories(build_assert INTERFACE ${CMAKE_CURRENT_SOURCE_DIR} ${ccan_base_path})
