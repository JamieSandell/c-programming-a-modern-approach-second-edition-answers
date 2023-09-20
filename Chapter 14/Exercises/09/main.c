/*
Write the following parameterized macros.

(a) CHECK(x,y,n) - Has the value 1 if both x and y fall between 0 and n-1, inclusive.
(b) MEDIAN(x,y,z) - Finds the median of x, y and z.
(c) POLYNOMIAL(x) - Computes the polynomial 3x5 + 2x4 - 5x3 - x2 + 7x - 6.

(a)
#define CHECK(x,y,n) (((x) >= 0 && (x) <= ((n) - 1)) && ((y) >= 0 && (y) <= ((n) - 1)))

(b)
#define MEDIAN(x,y,z) (((x) - (y)) * ((z) - (x)) >= 0 ? x : ((y) - (x)) * ((z) - (y)) >= 0 ? y : z)

(c)
#define POLYNOMIAL(x) ( (3 * ((x) * (x) * (x) * (x) * (x)))         \
                       +(2 * ((x) * (x) * (x) * (x)))               \
                       -(5 * ((x) * (x) * (x)))                     \
                       -((x) * (x)) + (7 * (x)) - 6 )
*/