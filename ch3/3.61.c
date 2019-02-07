// File: 3.61.c
// Author: iBug

/*
 * WARNING: Defunct
 */

long cread_alt(long* xp) {
    static const long z = 0;
    return *(xp ? xp : &z);
}
