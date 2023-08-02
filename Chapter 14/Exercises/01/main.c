/*
Write parameterized macros that compute the following values.

(a) The cube of x.
(b) The remainder when n is divided by 4.
(c) 1 if the product of x and y is less than 100, 0 otherwise.

Do your macros always work? If not, describe what arguments would make them fail.

#define CUBE(x) ((x) * (x) * (x))
Only arguments which would evaluate to a numeric type would work under this macro.

#define REMAINDER_4(n) ((n) % 4)
Only arguments which would evalute to a numeric type would work under this macro.

#define SMALL_PRODUCT(x, y) (((x) * (y)) < 100 ? 1 : 0)
Only arguments which would evaluate to a numeric type would work under this macro.
*/