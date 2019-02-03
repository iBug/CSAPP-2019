CC := gcc
CXX := g++
CFLAGS := -Wall -std=c11
TEST := ./test
export

.PHONY: all test

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
