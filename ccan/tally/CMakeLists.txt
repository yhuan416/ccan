cmake_minimum_required(VERSION 3.5)

include(${CMAKE_CURRENT_SOURCE_DIR}/../ccan.cmake)

# tally
add_library(tally STATIC tally.c)

target_include_directories(tally PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(tally ccan_config build_assert likely)

target_compile_options(tally PRIVATE ${CCAN_CFLAGS})
