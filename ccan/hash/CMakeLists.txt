cmake_minimum_required(VERSION 3.5)

include(${CMAKE_CURRENT_SOURCE_DIR}/../ccan.cmake)

# hash
add_library(hash STATIC hash.c)

# target_include_directories(hash PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(hash ccan_config build_assert)

target_compile_options(hash PRIVATE ${CCAN_CFLAGS})
