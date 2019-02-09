CODES := 3.60 3.61 3.62 3.64 3.70

PAGER ?= less
CODES_TEST := $(patsubst %,%-test,${CODES})

# Codes in this chapter compiles better with exactly -O1
CFLAGS += -O1

.PHONY: all test ${CODES_TEST} clean

all: $(patsubst %,%.s,${CODES})

test: all

${CODES_TEST}: %-test: %.s
	${PAGER} $^

%.s: %.c
	${CC} ${CFLAGS} -S -o $@ $^

clean:
	rm -f *.o *.s
