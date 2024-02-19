cmake_minimum_required(VERSION 3.5)

project(ccan)

set(WARN_CFLAGS -Wall -Wstrict-prototypes -Wold-style-definition -Wundef -Wmissing-prototypes -Wmissing-declarations -Wpointer-arith -Wwrite-strings -Wshadow=local)
set(CCAN_CFLAGS -g3 -ggdb ${WARN_CFLAGS} -DCCAN_STR_DEBUG=1)

# configurator tool, output to tools/configurator
add_executable(configurator tools/configurator/configurator.c)
set_target_properties(configurator PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/tools/configurator
)

# config.h
add_custom_target(config
    COMMAND configurator cc ${CCAN_CFLAGS} > ${CMAKE_CURRENT_SOURCE_DIR}/config.h
    DEPENDS configurator
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/tools/configurator
)

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
add_dependencies(ccan config)

target_include_directories(ccan PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_compile_options(ccan PRIVATE ${CCAN_CFLAGS})
