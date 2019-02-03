// File: 2.36-test.c
// Author: iBug

#include <stdio.h>
#include <limits.h>
#include <assert.h>

int tmult_ok(int x, int y);

int main() {
    if (sizeof(int) * CHAR_BIT != 32) {
        puts("Bad platform, test skipped");
    }

    assert(tmult_ok(0x7FFF, 0x10000) == 1);
    assert(tmult_ok(0x8000, 0x10000) == 0);
    assert(tmult_ok(0x7FFF, 0xFFFF0000) == 1);
    assert(tmult_ok(0x8000, 0xFFFF0000) == 1); // Special case
    assert(tmult_ok(0x8001, 0xFFFF0000) == 0);
    assert(tmult_ok(0xFFFF8000, 0xFFFF0000) == 0);
    assert(tmult_ok(0xFFFF8001, 0xFFFF0000) == 1);
    return 0;
}
