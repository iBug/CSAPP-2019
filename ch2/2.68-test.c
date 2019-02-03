// File: 2.68-test.c
// Author: iBug

#include <assert.h>

int lower_one_mask(int);

int main() {
    assert(lower_one_mask(6) == 0x3F);
    assert(lower_one_mask(17) == 0x1FFFF);
    return 0;
}
