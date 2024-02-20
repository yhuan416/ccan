cmake_minimum_required(VERSION 3.5)

include(${CMAKE_CURRENT_SOURCE_DIR}/../ccan.cmake)

# typesafe_cb
add_library(typesafe_cb INTERFACE)

target_include_directories(typesafe_cb INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(typesafe_cb INTERFACE ccan_config)
