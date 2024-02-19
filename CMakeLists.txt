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

# ccan
file(GLOB SOURCES "ccan/*/*.c")

# 排除 altstack jmap jset nfs ogg_to_pcm tal/talloc wwviaudio 这些文件
# ... Except stuff that needs external dependencies, which we exclude
list(FILTER SOURCES EXCLUDE REGEX ".*altstack.*")
list(FILTER SOURCES EXCLUDE REGEX ".*jmap.*")
list(FILTER SOURCES EXCLUDE REGEX ".*jset.*")
list(FILTER SOURCES EXCLUDE REGEX ".*nfs.*")
list(FILTER SOURCES EXCLUDE REGEX ".*ogg_to_pcm.*")
list(FILTER SOURCES EXCLUDE REGEX ".*tal/talloc.*")
list(FILTER SOURCES EXCLUDE REGEX ".*wwviaudio.*")

list(FILTER SOURCES EXCLUDE REGEX ".*compiler.*")
list(FILTER SOURCES EXCLUDE REGEX ".*htable.*")

add_library(ccan STATIC ${SOURCES})
add_dependencies(ccan ccan_config_h)

target_include_directories(ccan PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_compile_options(ccan PRIVATE ${CCAN_CFLAGS})
