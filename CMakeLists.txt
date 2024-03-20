cmake_minimum_required(VERSION 3.5)

project(ccan)

include(config.cmake)

# tools/configurator
add_subdirectory(tools/configurator)

# ccan_config
add_library(ccan_config INTERFACE)
target_include_directories(ccan_config INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
add_dependencies(ccan_config gen_config_h)

# ccan
add_subdirectory(ccan/compiler)
add_subdirectory(ccan/build_assert)
add_subdirectory(ccan/version)
add_subdirectory(ccan/typesafe_cb)
add_subdirectory(ccan/ptrint)
add_subdirectory(ccan/htable)
add_subdirectory(ccan/order)
add_subdirectory(ccan/avl)
add_subdirectory(ccan/base64)
add_subdirectory(ccan/hash)
add_subdirectory(ccan/likely)
add_subdirectory(ccan/tally)
add_subdirectory(ccan/time)
add_subdirectory(ccan/endian)
add_subdirectory(ccan/siphash)
add_subdirectory(ccan/noerr)
add_subdirectory(ccan/net)
add_subdirectory(ccan/opt)
add_subdirectory(ccan/cast)
add_subdirectory(ccan/pr_log)
add_subdirectory(ccan/talloc)
add_subdirectory(ccan/block_pool)
