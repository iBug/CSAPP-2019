// File: 2.93-test.c
// Author: iBug

#include <assert.h>
#include "bit-float.h"

#include <math.h>

float_bits float_absval(float_bits);

int main() {
    assert(sizeof(float_bits) == 4);
    assert(sizeof(float) == 4);

    union {
        float f;
        float_bits b;
    } in, out;

    in.f = 123.456f, out.f = 123.456f;
    assert(float_absval(in.b) == out.b);

    in.f = -123.456f, out.f = 123.456f;
    assert(float_absval(in.b) == out.b);

    in.f = -0.0f, out.f = 0.0f;
    assert(float_absval(in.b) == out.b);

    in.f = -INFINITY, out.f = INFINITY;
    assert(float_absval(in.b) == out.b);

    in.f = NAN, out.f = NAN;
    assert(float_absval(in.b) == out.b);
    return 0;
}
