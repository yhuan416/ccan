cmake_minimum_required(VERSION 3.5)

include(${CMAKE_CURRENT_SOURCE_DIR}/../ccan.cmake)

# noerr
add_library(noerr STATIC noerr.c)

# target_include_directories(noerr PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(noerr ccan_config)

target_compile_options(noerr PRIVATE ${CCAN_CFLAGS})
