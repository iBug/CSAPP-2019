// File: 2.92.c
// Author: iBug

#include "bit-float.h"

float_bits float_negate(float_bits f) {
    if ((f & 0x7F800000) == 0x7F800000 && (f & 0x007FFFFF) != 0)
        return f;
    return f ^ 0x80000000;
}
