cmake_minimum_required(VERSION 3.5)

include(${CMAKE_CURRENT_SOURCE_DIR}/../ccan.cmake)

# typesafe_cb
add_library(typesafe_cb INTERFACE)

add_dependencies(typesafe_cb ccan_config_h)

target_include_directories(typesafe_cb INTERFACE ${CMAKE_CURRENT_SOURCE_DIR} ${ccan_base_path})
