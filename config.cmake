
set(WARN_CFLAGS -Wall -Wstrict-prototypes -Wold-style-definition -Wundef -Wmissing-prototypes -Wmissing-declarations -Wpointer-arith -Wwrite-strings -Wshadow=local)

set(CCAN_CFLAGS -g3 -ggdb ${WARN_CFLAGS} -DCCAN_STR_DEBUG=1)
