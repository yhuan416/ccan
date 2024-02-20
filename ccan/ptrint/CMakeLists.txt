cmake_minimum_required(VERSION 3.5)

include(${CMAKE_CURRENT_SOURCE_DIR}/../ccan.cmake)

# ptrint
add_library(ptrint INTERFACE)

target_include_directories(ptrint INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(ptrint INTERFACE compiler build_assert ccan_config)
