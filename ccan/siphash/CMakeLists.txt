cmake_minimum_required(VERSION 3.5)

include(${CMAKE_CURRENT_SOURCE_DIR}/../ccan.cmake)

# siphash
add_library(siphash STATIC siphash.c)

# target_include_directories(siphash PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(siphash endian ccan_config)

target_compile_options(siphash PRIVATE ${CCAN_CFLAGS})
