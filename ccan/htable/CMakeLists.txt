cmake_minimum_required(VERSION 3.5)

include(${CMAKE_CURRENT_SOURCE_DIR}/../ccan.cmake)

# htable
add_library(htable STATIC htable.c)

# target_include_directories(htable PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(htable compiler ccan_config)

target_compile_options(htable PRIVATE ${CCAN_CFLAGS})
