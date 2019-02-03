// File: 2.30.c
// Author: iBug

int tadd_ok(int x, int y) {
    if ((x ^ y) >> 31)
        return 1;  // A positive number and a negative integer always add without problem
    if (x < 0)
        return (x + y) < x;
    if (x > 0)
        return (x + y) > x;
}
