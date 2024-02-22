cmake_minimum_required(VERSION 3.5)

include(${CMAKE_CURRENT_SOURCE_DIR}/../ccan.cmake)

# cast
add_library(cast INTERFACE)

# target_include_directories(cast INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(cast INTERFACE ccan_config)
