cmake_minimum_required(VERSION 3.5)

include(${CMAKE_CURRENT_SOURCE_DIR}/../ccan.cmake)

# build_assert
add_library(build_assert INTERFACE)

target_include_directories(build_assert INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(build_assert INTERFACE ccan_config)
