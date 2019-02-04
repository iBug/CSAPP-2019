// File: 2.93.c
// Author: iBug

#include "bit-float.h"

float_bits float_absval(float_bits f) {
    if ((f & 0x7F800000) == 0x7F800000 && (f & 0x007FFFFF) != 0)
        return f;
    return f & 0x7FFFFFFF;
}
