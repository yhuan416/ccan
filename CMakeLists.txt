cmake_minimum_required(VERSION 3.5)

project(ccan)

include(config.cmake)

add_subdirectory(tools/configurator)

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

add_library(ccan STATIC ${SOURCES})
add_dependencies(ccan ccan_config)

target_include_directories(ccan PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_compile_options(ccan PRIVATE ${CCAN_CFLAGS})
