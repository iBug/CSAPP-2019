// File: 2.64.c
// Author: iBug

int any_odd_one(unsigned x) {
    return 1 && (x & 0xAAAAAAAA);
}
