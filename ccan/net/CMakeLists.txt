cmake_minimum_required(VERSION 3.5)

include(${CMAKE_CURRENT_SOURCE_DIR}/../ccan.cmake)

# net
add_library(net STATIC net.c)

# target_include_directories(net PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(net ccan_config)

target_compile_options(net PRIVATE ${CCAN_CFLAGS})
