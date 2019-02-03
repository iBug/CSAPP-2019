.PHONY: all %-test clean

all: 2.27.o 2.30.o 2.36.o

test: 2.27-test 2.30-test 2.36-test

clean:
	rm -f test *.o

%.o: %.c
	${CC} -c -o $@ $^

%-test: %.o %-test.o
	${CC} -o ${TEST} $^
	${TEST}
