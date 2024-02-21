cmake_minimum_required(VERSION 3.5)

include(${CMAKE_CURRENT_SOURCE_DIR}/../ccan.cmake)

# base64
add_library(base64 STATIC base64.c)

# target_include_directories(base64 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(base64 ccan_config)

target_compile_options(base64 PRIVATE ${CCAN_CFLAGS})
