// File: 2.65-test.c
// Author: iBug

#include <assert.h>

int odd_ones(unsigned);

int main() {
    assert(odd_ones(12345) == 0);
    assert(odd_ones(1234567) == 1);
    return 0;
}
