.PHONY: all %-test

all: 2.27.o

test: 2.27-test

%.o: %.c
	${CC} -c -o $@ $^

2.27-test: 2.27.o 2.27-test.o
	${CC} -o ${TEST} $^
	${TEST}
