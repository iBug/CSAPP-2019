CC := gcc
CXX := g++
CFLAGS := -O0 -g3 -Wall -std=c11
TEST := ./test
export

.PHONY: all test clean

all:
	@for dir in ch*/; do \
		echo "Running 'make' in $$dir";\
		make --no-print-directory -C $$dir; \
	done

test:
	@for dir in ch*/; do \
		echo "Running 'make test' in $$dir";\
		make --no-print-directory -C $$dir test; \
	done

clean:
	@for dir in ch*/; do \
		echo "Running 'make clean' in $$dir";\
		make --no-print-directory -C $$dir clean; \
	done
