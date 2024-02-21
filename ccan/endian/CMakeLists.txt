cmake_minimum_required(VERSION 3.5)

include(${CMAKE_CURRENT_SOURCE_DIR}/../ccan.cmake)

# endian
add_library(endian INTERFACE)

# target_include_directories(endian INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(endian INTERFACE ccan_config)
