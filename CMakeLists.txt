cmake_minimum_required(VERSION 3.5)

project(ccan)

include(config.cmake)

# tools/configurator
add_subdirectory(tools/configurator)

# ccan
add_subdirectory(ccan/compiler)
add_subdirectory(ccan/build_assert)
add_subdirectory(ccan/version)
add_subdirectory(ccan/typesafe_cb)
add_subdirectory(ccan/ptrint)
add_subdirectory(ccan/htable)
add_subdirectory(ccan/order)
add_subdirectory(ccan/avl)
