// File: 2.61-test.c
// Author: iBug

#include <stdio.h>
#include <limits.h>
#include <assert.h>

int A(int);
int B(int);
int C(int);
int D(int);

int main() {
    assert(A(123) == 1);
    assert(A(0xFFFFFFFF) == 1);
    assert(A(0) == 0);

    assert(B(123) == 1);
    assert(B(0xFFFFFFFF) == 0);
    assert(B(0) == 1);

    assert(C(123) == 1);
    assert(C(0xFFFFFFFF) == 1);
    assert(C(0) == 0);
    assert(C(0xFFFFFF00) == 0);

    assert(D(123) == 0);
    assert(D(0xFFFFFFFF) == 1);
    assert(D(0) == 0);
    assert(D(0x00FFFFFF) == 0);

    puts("Test passed for 2.61");
    return 0;
}
