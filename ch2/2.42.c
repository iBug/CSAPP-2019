// File: 2.42.c
// Author: iBug

int div16(int x) {
    return (x + ((x >> 31) & 0xF)) >> 4;
}
