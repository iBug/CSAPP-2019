// File: 2.64-test.c
// Author: iBug

#include <assert.h>

int any_odd_one(unsigned);

int main() {
    assert(any_odd_one(12345) == 1);
    assert(any_odd_one(349525) == 0);
    return 0;
}
