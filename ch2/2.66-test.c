// File: 2.66-test.c
// Author: iBug

#include <assert.h>

int leftmost_one(unsigned);

int main() {
    assert(leftmost_one(0xFF00) == 0x8000);
    assert(leftmost_one(0x6600) == 0x4000);
    return 0;
}
