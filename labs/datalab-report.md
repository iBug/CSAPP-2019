# Report of Data Lab of CS:APP 2019

Student No.: *Redacted*

## Integer Exercises

### 1. Bitwise AND

The first task is to compute bitwise AND using only `~ |` (bitwise inversion and bitwise OR). It is not any difficult given the following famous "AND gate" implementation in Minecraft Redstone circuits:

![image](https://gamepedia.cursecdn.com/minecraft_gamepedia/4/4c/ANDgate.png?version=554d1aa0d427a285fda81e02d69aed47)

Translating the above restone circuit to C code, and here's the result:

```c
return ~((~x) | (~y));
```

### 2. Get byte

This task is to retrieve a specific byte from a DWORD (4 bytes). To cut off (mask off) unwanted bytes, left-shifting `0xFF` by `8*n` yields an available mask for use. Again, multiplication is not allowed, so you have to replace `8*n` with `n << 3`.

```c
return ((x & (0xFF << (n << 3))) >> (n << 3)) & 0xFF;
```

### 3. Logical right shift

This task requires an implementation of logical right shift using arithmetic right shift. The primary difference between arithmetic and logic right shift is that an arithmetic shift fills highest bits with the sign bit, while a logical shift always fills zeros. With this in mind, to implement a logical right shift, the core work is to replace filler bits with zeros.

A prototype of the idea is demonstrated by the following code:

```c
return (x >> n) & ((unsigned) -1 >> n)
```

And then the task boils down to the implementation of `(unsigned) -1 >> n`. An easy way to do this is to left shift `-1` by `32 - n` bits and the invert the result, given that `-1` can be acquired from `~0`:

```c
(unsigned) -1 << n  <==  ~((~0) << (32 - n))
```

However, as shifting by 32 bits is undefined behavior when `n` equals to 0, we need some workaround here, and so is it when it talks about the unavailability of `32 - n` (the subtraction operator).

Things isn't any hard, still. Given the fact that `n` has a maximum value of 31, the expression `32 - n` can be re-written as:

```c
32 - n  <==  1 + (31 - n)  <==  1 + (n ^ 31)
```

So here is the final result:

```c
return (x >> n) & ~(((~0) << 1) << (n ^ 31));
```

### 4. Bit count

This is my favorite bit manipulation task in this lab.

To count number of bits in a number, there's a x86 instruction `POPCNT` for the job. That isn't relevant here however.

I picked the following approach: Group bits by 2 and count, then group bits by 4 and count, then 8, then 16, and finally 32.

To do so, a few masks are needed. They are:

```c
0b 01010101 01010101 01010101 01010101
0b 00110011 00110011 00110011 00110011
0b 00001111 00001111 00001111 00001111
0b 00000000 11111111 00000000 11111111  // Not necessary actually
```

Then, to group bits, I use `(x & mask) + ((x >> 1) & mask)`.

But as the limitations instate, constant numbers over 255 cannot be used directly, so consturcting them is a must at the first place.

Here's the final code:

```c
int t;
t |= 0x55 | (0x55 << 8);
int mask_1 = t | (t << 16); // Mask 1 = 0x55555555
t = 0x33 | (0x33 << 8);
int mask_2 = t | (t << 16); // Mask 2 = 0x33333333
t = 0x0F | (0x0F << 8);
int mask_3 = t | (t << 16); // Mask 3 = 0x0F0F0F0F

x = (x & mask_1) + ((x >> 1) & mask_1);
x = (x & mask_2) + ((x >> 2) & mask_2);
x = (x & mask_3) + ((x >> 4) & mask_3);
x += x >> 8;
return (x + (x >> 16)) & 0xFF;
```

### 5. Bang (`!`)

Implementing the `!` operator without it is another interesting task. The complexity of this task completely depends whether you're smart enough to figure out the ultimate fact that 0 is the only value of `x` such that neither `x` nor `-x` is negative. Once this is known, everything's a piece of cake.

```c
int y = 1 + ~x; // y = -x
return ~((x + y) >> 31) & 1;
```

### 6. Tmin

The minimum two's complement integer is `0b 10000000 00000000 00000000 00000000`, so the answer is:

```c
return 1 << 31;
```

### 7. FitsBits

This is just hard work. To check if a number fits into the range of an n-bit 2's complement integer, the easy way is to check if all bits to the left of the n-th bit are the same as the sign bit. To fill all higher bits with the sign bit, shifting left then right back is one way:

```c
n = 32 - n;
int filled = (x << n) >> n;
```

And the last thing is to check if `filled == x`. Full code is:

```c
n = 1 + (n ^ 31);
int y = (x << n) >> n;
return !(x ^ y);
```

### 8. Divide by powers of 2

This task looks easy at first glance, as `x >> n` is a very intuitive answer. However there's a serious flaw in that straightforward approach: It produces wrong answers for negative numbers.

To fix the flaw, check if the "shifted out" numbers are all zero for a negative input number. If not, add 1 to the result for the correct answer.

```c
int y = (x >> 31) & !!(x & ~((~0) << n));
return (x >> n) + y;
```

### 9. Negate

Nothing hard... `(-x) == ((~x) + 1)`

### 10. Is positive

Again nothing hard... just return the negation of the sign bit, plus a special handling of zero.

### 11. Is less or equal

This one is also interesting due to the extreme cases to handle (multiple cases with `INT_MIN` and `INT_MAX`), so I split this into multiple cases:

- `x == y` should obviously give 1, so the first part comes `!(x ^ y)`
- `x < 0 && y >= 0` should also give 1, so the second part comes `((x >> 31) & !(y >> 31))`
- The last part checks if `x - y < 0`, so it looks like `(1 + x + ~y) >> 31`, which gives `-1` when `x - y < 0`.
- To handle extreme cases, I added a "sanity check" to ensure no result is given when `x >= 0 && y < 0`. This works as a mask around the other three results.

The final result is:

```c
return (
  !(x ^ y) |
  ((x >> 31) & !(y >> 31)) |
  (((1 + x + ~y) >> 31))
) & (
   !(
     !(x >> 31) & (y >> 31)
   )
);
```

### 12. i Log 2

Computing $\textrm{floor}(\log_2x)$, interesting yet exhausting to play with.

The idea is to first check if the top 16 bits contains any data, if so, construct a new mask to check if the top 8 bits of the 16-bit chunk where the top bit may be to check if the result should go up by 8, and similar for 4, 2 and 1. Then the result is added up.

I didn't find a descriptive way to explain the algorithm, so I decided to just put the code here.

```c
int ilog2(int x) {
  int mask_1 = (~0) << 16; // 0xFFFF0000
  int mask_2 = mask_1 ^ (mask_1 >> 8) ^ (mask_1 << 8); // 0xFF00FF00
  int mask_3 = mask_2 ^ (mask_2 >> 4) ^ (mask_1 << 12); // 0xF0F0F0F0
  int mask_4 = mask_3 ^ (mask_3 >> 2) ^ (mask_1 << 14); // 0xCCCCCCCC
  int mask_5 = mask_4 ^ (mask_4 >> 1) ^ (mask_1 << 15); // 0xAAAAAAAA

  int r = 0, m = ~0, t = 0;
  t = !!(x & m & mask_1);
  r += t << 4;
  m &= mask_1 ^ ~((t << 31) >> 31);

  t = !!(x & m & mask_2);
  r += t << 3;
  m &= mask_2 ^ ~((t << 31) >> 31);

  t = !!(x & m & mask_3);
  r += t << 2;
  m &= mask_3 ^ ~((t << 31) >> 31);

  t = !!(x & m & mask_4);
  r += t << 1;
  m &= mask_4 ^ ~((t << 31) >> 31);

  t = !!(x & m & mask_5);
  r += t << 0;
  m &= mask_5 ^ ~((t << 31) >> 31);
  return r;
}
```

## Floating-point Exercises

### 13. Floating-point negation

The first floating-point task isn't any hard - negate the number if it's finite. The process is also simple: Check if it's NaN, and flip the sign bit if not.

```c
unsigned float_neg(unsigned uf) {
  if ((uf & 0x7F800000) == 0x7F800000 && uf & 0x007FFFFF) {
    return uf; // NaN
  }
  return uf ^ 0x80000000;
}
```

### 14. Integer to float

The next FP task is to convert an integer to FP. Since the minimum non-zero integral value is 1, there's no need to consider denormalized cases. So the process starts with a plain zero check before starting to find the exponent of the value.

One final point is the rounding handling. Unlike integers, floating-point needs to be rounded to the nearest "even" value, so that's a bit of work to create a correct rounding handler.

The code is as follows:

```c
unsigned float_i2f(int x) {
  if (x == 0)
    return 0;

  unsigned sign = x >> 31, abs = sign ? -x : x, exp = 158;
  while ((abs & 0x80000000) == 0) {
    abs <<= 1;
    exp -= 1;
  }
  unsigned frac = (abs >> 8) & 0x7FFFFF;
  // Round up
  if (((abs & 0xFF) > 0x80) || (abs & 0x180) == 0x180) {
    frac += 1;
    if (frac > 0x7FFFFF) {
      exp += 1;
      frac = (frac & 0x7FFFFF) >> 1;
    }
  }
  return (sign << 31) | (exp << 23) | frac;
}
```

### 15. Double an FP value

The last FP task is to calculate $2\times f$ for an FP value $f$. This is the most complex one of the three because it requires proper handling of all FP values, including denormalized, normalized, overflowing, infinity and NaN.

The first thing to check is denormalized numbers. To get double the value, double the fraction part, and convert it to normalized FP if an overflow occurs.

The second thing is normalized numbers. Doubling the value is particularly simple except for the handling of overflowing to infinity.

If a value is neither denormalized and normalized, then it must be either infinity or NaN, which means it's time to return the value verbatim.

The final code is shown below:

```c
unsigned float_twice(unsigned uf) {
  unsigned sign = uf >> 31, exp = (uf >> 23) & 0xFF, frac = uf & 0x7FFFFF;
  if (exp == 0) { // Denormalized
    frac *= 2;
    if (frac > 0x7FFFFF) { // Overflow
      exp = 1;
      frac &= 0x7FFFFF;
    }
  } else if (exp < 0xFE) {
    exp += 1;
  } else if (exp == 0xFE) { // Going to overflow
    return (sign << 31) | 0x7F800000;
  } else { // Inf or NaN
    return uf;
  }
  return (sign << 31) | (exp << 23) | frac;
}
```

