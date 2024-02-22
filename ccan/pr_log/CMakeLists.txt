cmake_minimum_required(VERSION 3.5)

include(${CMAKE_CURRENT_SOURCE_DIR}/../ccan.cmake)

# pr_log
add_library(pr_log STATIC pr_log.c)

# target_include_directories(pr_log PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(pr_log ccan_config compiler)

target_compile_options(pr_log PRIVATE ${CCAN_CFLAGS})
