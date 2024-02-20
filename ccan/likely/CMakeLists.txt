cmake_minimum_required(VERSION 3.5)

include(${CMAKE_CURRENT_SOURCE_DIR}/../ccan.cmake)

# likely
add_library(likely STATIC likely.c)

target_include_directories(likely PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(likely ccan_config htable hash)

target_compile_options(likely PRIVATE ${CCAN_CFLAGS})
