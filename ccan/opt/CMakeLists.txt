cmake_minimum_required(VERSION 3.5)

include(${CMAKE_CURRENT_SOURCE_DIR}/../ccan.cmake)

# opt
add_library(opt STATIC opt.c helpers.c parse.c usage.c)

# target_include_directories(opt PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(opt ccan_config)

target_compile_options(opt PRIVATE ${CCAN_CFLAGS})
