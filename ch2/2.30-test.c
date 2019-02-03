// File: 2.30-test.c
// Author: iBug

#include <stdio.h>
#include <assert.h>

int tadd_ok(unsigned x, unsigned y);

int main() {
    assert(tadd_ok(0x7FFFFFFF, 0x80000000) == 1);
    assert(tadd_ok(0x7FFFFFFF, 0x7FFFFFFF) == 0);
    assert(tadd_ok(0x80000000, 0x80000000) == 0);
    puts("Test passed for 2.30");
    return 0;
}
