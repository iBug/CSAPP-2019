CODES = 2.27 2.30 2.36 2.42 2.61 2.63 2.64 2.65 2.66 2.68 2.92 2.93

CFLAGS += -fwrapv

.PHONY: all %-test clean

all: $(patsubst %,%.o,${CODES})

test: $(patsubst %,%-test,${CODES})

clean:
	rm -f ${TEST} *.o

%.o: %.c
	${CC} -c ${CFLAGS} -o $@ $^

%-test: %.o %-test.o
	${CC} -o ${TEST} $^
	@${TEST} && echo "Test passed for $*"
