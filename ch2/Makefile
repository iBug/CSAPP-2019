CODES = 2.27 2.30 2.36 2.42 2.61 2.63

.PHONY: all %-test clean

all: $(patsubst %,%.o,${CODES})

test: $(patsubst %,%-test,${CODES})

clean:
	rm -f test *.o

%.o: %.c
	${CC} -c -o $@ $^

%-test: %.o %-test.o
	${CC} -o ${TEST} $^
	@${TEST}
