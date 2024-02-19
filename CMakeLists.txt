cmake_minimum_required(VERSION 3.5)

project(ccan)

# 获取ccan/xx/*.c 文件, 但是不继续递归获取
file(GLOB SOURCES "ccan/*/*.c")

# 排除 altstack jmap jset nfs ogg_to_pcm tal/talloc wwviaudio 这些文件
list(FILTER SOURCES EXCLUDE REGEX ".*altstack.*")
list(FILTER SOURCES EXCLUDE REGEX ".*jmap.*")
list(FILTER SOURCES EXCLUDE REGEX ".*jset.*")
list(FILTER SOURCES EXCLUDE REGEX ".*nfs.*")
list(FILTER SOURCES EXCLUDE REGEX ".*ogg_to_pcm.*")
list(FILTER SOURCES EXCLUDE REGEX ".*tal/talloc.*")
list(FILTER SOURCES EXCLUDE REGEX ".*wwviaudio.*")

set(WARN_CFLAGS -Wall -Wstrict-prototypes -Wold-style-definition -Wundef -Wmissing-prototypes -Wmissing-declarations -Wpointer-arith -Wwrite-strings -Wshadow=local)
set(CCAN_CFLAGS -g3 -ggdb)

add_library(ccan STATIC ${SOURCES})

target_include_directories(ccan PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_definitions(ccan PUBLIC CCAN_STR_DEBUG=1)
target_compile_options(ccan PUBLIC ${WARN_CFLAGS} ${CCAN_CFLAGS})
