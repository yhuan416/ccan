cmake_minimum_required(VERSION 3.5)

include(${CMAKE_CURRENT_SOURCE_DIR}/../ccan.cmake)

# version
add_library(version INTERFACE)

# target_include_directories(version INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(version INTERFACE ccan_config)
