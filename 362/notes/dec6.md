# IEEE Floating Point Multiplication

`0xBFC00000` $\rightarrow$ $\boxed{1}\boxed{011 1111 1}\boxed{100 0000 0000 0000 0000 0000}$

= $\boxed{-1} * 1\boxed{.5} *$ 2^ $\boxed{0}$
- Trick here: we always assume a 1.`F` format, so we don't need to write the 1 explicitly. That's why the 1000 0000... becomes 1.5 and not 0.5.
- ANOTHER trick: the exponent is always 127 + the number of bits. So take 011 1111 1 and subtract 127 to get 0.

0xBFC00000 * 0x41600000
= (-1 * 1.5 * 2^0) * (-1 * 1.75 * 2^3) = -21 which interpreted as exponent is: 1 * 1.0101 in binary * 2^4 (we will learn how to do this later)

**Why bias the exponent?**
- Biasing so that comparing two FP numbers is like comparing two unsigned integers.

### Floating point addition
Recall elementary school, if we want to add scientific notation, we need to make the exponents the same. Same thing here. Start by comparing the exponents. If they're different, shift the smaller one to the right until they're the same. Then add the mantissas and normalize.

Actual: e1 = 12, e2 = 13, e* = 25

IEEE: E1 = 12 + 127 = 139, E2 = 13 + 127 = 140,

E* = E1 - 127 + E1 - 127.
***
Summary: 
1. add biased exponents and then subtract bias after adding.
2. Multiply mantissas, normalize, and round.
3. Set sign bit to 0 if positive, 1 if negative.


### Division
Subtract bias, subtract exponents, and subtract bias. Then divide mantissas and normalize.

### Binary Rounding
- x.xx $\underline{x}$ 1...1.. -> up
- x.xx $\underline{x}$ 0000 -> LSB = 0 so round down
- x.xx $\underline{x}$ 0xx1x -> down
- x.xx $\underline{x}$ 00000 -> unchanged