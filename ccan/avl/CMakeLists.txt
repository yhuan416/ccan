cmake_minimum_required(VERSION 3.5)

include(${CMAKE_CURRENT_SOURCE_DIR}/../ccan.cmake)

# avl
add_library(avl STATIC avl.c)

add_dependencies(avl ccan_config_h order)

target_include_directories(avl PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${ccan_base_path})

target_link_libraries(avl order)

target_compile_options(avl PRIVATE ${CCAN_CFLAGS})
