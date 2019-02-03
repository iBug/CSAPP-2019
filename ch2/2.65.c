// File: 2.65.c
// Author: iBug

int odd_ones(unsigned x) {
    x = x ^ (x >> 16);
    x = x ^ (x >> 8);
    x = x ^ (x >> 4);
    x = x ^ (x >> 2);
    x = x ^ (x >> 1);
    return x & 1;
}
