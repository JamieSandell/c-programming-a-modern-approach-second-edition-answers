/*
Let GENERIC_MAX be the following macro:

#define GENERIC_MAX(type)       \
type type##_max(type x, type y) \
{                               \
    return x > y ? x : y;       \
}   

(a) Show the preprocessor's expansion of GENERIC_MAX(long).

long long_max(long x, long y)
{
    return x > y ? x : y;
}

(b) Explain why GENERIC_MAX doesn't work for basic types such as unsigned long.

A function name cannot have any spaces in it.
Unsigned long would yield:

unsigned long unsigned long_max(unsigned long x, unsigned long y)
{
    return x > y ? x : y;
}

(c) Describe a technique that would allow us to use GENERIC_MAX with basic types such as
    unsigned long.

Use a custome typedef name without spaces.
For example:

typedef unsigned long u_long;

Then call the macro with GENERIC_MAX(ulong)

this would expand to:

ulong ulong_max(ulong x, ulong y)
{
    return x > y > x : y;
}
*/