// File: 2.36.c
// Author: iBug

#include <stdint.h>

int tmult_ok(int x, int y) {
    int64_t p = (int64_t)x * (int64_t)y;
    return (p >> 31) == -(signed)(((unsigned)x ^ (unsigned)y) >> 31);  // Check if sign matches
}
