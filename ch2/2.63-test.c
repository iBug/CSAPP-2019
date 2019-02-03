// File: 2.63-test.c
// Author: iBug


#include <stdio.h>
#include <assert.h>

unsigned srl(unsigned x, int k);
int sra(int x, int k);

int main() {
    assert(srl(1234U, 5) == (1234U >> 5));
    assert(srl(987654321U, 7) == (987654321U >> 7));

    assert(sra(1234, 5) == (1234 >> 5));
    assert(sra(-12345, 6) == (-12345 >> 6));

    puts("Test passed for 2.63");
    return 0;
}
