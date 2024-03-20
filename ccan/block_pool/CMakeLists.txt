cmake_minimum_required(VERSION 3.5)

include(${CMAKE_CURRENT_SOURCE_DIR}/../ccan.cmake)

# block_pool
add_library(block_pool STATIC block_pool.c)

# target_include_directories(block_pool PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(block_pool ccan_config talloc)

target_compile_options(block_pool PRIVATE ${CCAN_CFLAGS})
