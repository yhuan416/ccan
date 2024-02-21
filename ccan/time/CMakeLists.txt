cmake_minimum_required(VERSION 3.5)

include(${CMAKE_CURRENT_SOURCE_DIR}/../ccan.cmake)

# time
add_library(time STATIC time.c)

# dont include the current directory
# target_include_directories(time PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(time ccan_config)

target_compile_options(time PRIVATE ${CCAN_CFLAGS})
