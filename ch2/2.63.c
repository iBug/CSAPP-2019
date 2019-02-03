// File: 2.63.c
// Author: iBug

unsigned srl(unsigned x, int k) {
    /* Perform shift arithmetically */
    unsigned xsra = (int) x >> k;

    unsigned mask = (1 << (8 * sizeof(int) - k)) - 1;
    return xsra & mask;
}

int sra(int x, int k) {
    /* Perform shift logically */
    int xsrl = (unsigned) x >> k;

    /* Get MSB */
    int msb = (unsigned) x >> (8 * sizeof(int) - 1);

    int mask = ~(msb - 1) & ~((1U << (8 * sizeof(int) - k)) - 1);
    return xsrl | mask;
}
