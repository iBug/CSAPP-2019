// File: 2.42-test.c
// Author: iBug

#include <stdio.h>
#include <limits.h>
#include <assert.h>

int div16(int x);

int main() {
    if (sizeof(int) * CHAR_BIT != 32) {
        puts("Bad platform, test skipped");
    }

    assert(div16(333) == 333 / 16);
    assert(div16(8964) == 8964 / 16);
    assert(div16(-1) == -1 / 16);
    assert(div16(-2147483648) == -2147483648 / 16);
    return 0;
}
