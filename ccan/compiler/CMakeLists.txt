cmake_minimum_required(VERSION 3.5)

include(${CMAKE_CURRENT_SOURCE_DIR}/../ccan.cmake)

# compiler
add_library(compiler INTERFACE)

# target_include_directories(compiler INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(compiler INTERFACE ccan_config)
