cmake_minimum_required(VERSION 3.5)

include(${CMAKE_CURRENT_SOURCE_DIR}/../ccan.cmake)

# order
add_library(order STATIC order.c)

add_dependencies(order ccan_config_h typesafe_cb ptrint)

target_include_directories(order PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${ccan_base_path})

target_link_libraries(order typesafe_cb ptrint)

target_compile_options(order PRIVATE ${CCAN_CFLAGS})
