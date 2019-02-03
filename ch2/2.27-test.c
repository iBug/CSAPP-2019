// File: 2.27-test.c
// Author: iBug

#include <stdio.h>
#include <assert.h>

int uadd_ok(unsigned x, unsigned y);

int main() {
    assert(uadd_ok(0x80000000U, 0x80000000U) == 0);
    assert(uadd_ok(0x7FFFFFFFU, 0x7FFFFFFFU) == 1);
    return 0;
}
