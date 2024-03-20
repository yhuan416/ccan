cmake_minimum_required(VERSION 3.5)

include(${CMAKE_CURRENT_SOURCE_DIR}/../ccan.cmake)

# base64
add_library(talloc STATIC talloc.c)

# target_include_directories(talloc PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(talloc ccan_config typesafe_cb compiler)

target_compile_options(talloc PRIVATE ${CCAN_CFLAGS})
