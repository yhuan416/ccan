cmake_minimum_required(VERSION 3.5)

include(${CMAKE_CURRENT_SOURCE_DIR}/../ccan.cmake)

# avl
add_library(avl STATIC avl.c)

target_include_directories(avl PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(avl ccan_config order)

target_compile_options(avl PRIVATE ${CCAN_CFLAGS})
