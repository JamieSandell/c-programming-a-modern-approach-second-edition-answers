/*
Assume that the fraction structure contains two members: numerator and denomi-
nator (both of type int). Write functions that perform the following operations on frac-
tions:

(a) Reduce the fraction f to lowest terms. Hint: To reduce a fraction to lowest terms, first
    compute the greates common divison (GCD) of the numerator and denominator. Then
    divide both the numerator and denominator by the GCD.
(b) Add the fractions f1 and f2.
(c) Subtract the fraction f2 from the fraction f1.
(d) Multiply the fractions f1 and f2.
(e) Divide the fraction f1 by the fraction f2.

The fractions f, f1 and f2 will be arguments of type struct fraction: each function
will return a value of type struct fraction. The fractions returned by the functions in
parts (b)-(e) should be reduced to lowest terms. Hint: You may use the function from part
(a) to help write the functions in parts (b)-(e).
*/

#include <stdlib.h>

struct fraction
{
    int numerator;
    int denominator;
};

int gcd(int numerator, int denominator);
struct fraction lowest_terms(const struct fraction *f);
struct fraction add(const struct fraction *f1, const struct fraction *f2);
struct fraction subtract(const struct fraction *f1, const struct fraction *f2);
struct fraction multiply(const struct fraction *f1, const struct fraction *f2);
struct fraction divide(const struct fraction *f1, const struct fraction *f2);

int main(void)
{
    return EXIT_SUCCESS;
}

int gcd(int numerator, int denominator)
{
    int gcd, remainder;

    while (numerator != 0)
    {
        remainder = numerator % denominator;
        denominator = numerator;
        numerator = remainder;
    }

    gcd = denominator;

    return gcd;
}

struct fraction lowest_terms(const struct fraction *f) // (a)
{
    int _gcd = gcd(f->numerator, f->denominator);
    struct fraction result =
    {
        .numerator = f->numerator / _gcd,
        .denominator = f->denominator / _gcd
    };
    return result;
}

struct fraction add(const struct fraction *f1, const struct fraction *f2) // (b)
{
    struct fraction result =
    {
        .numerator = (f1->numerator * f2->denominator) + (f2->numerator * f1->denominator),
        .denominator = f1->denominator * f2->denominator
    };
    result = lowest_terms(&result);
    return result;
}

struct fraction subtract(const struct fraction *f1, const struct fraction *f2) // (c)
{
    struct fraction result = 
    {
        .numerator = (f1->numerator * f2->denominator) - (f2->numerator * f1->denominator),
        .denominator = f1->denominator * f2->denominator
    };
    result = lowest_terms(&result);
    return result;
}

struct fraction multiply(const struct fraction *f1, const struct fraction *f2) // (d)
{
    struct fraction result =
    {
        .numerator = f1->numerator * f2->numerator,
        .denominator = f2->denominator * f2->denominator
    };

    result = lowest_terms(&result);

    return result;
}

struct fraction divide(const struct fraction *f1, const struct fraction *f2) // (e)
{
    struct fraction result =
    {
        .numerator = f1->numerator * f2->denominator,
        .denominator = f1->denominator * f2->numerator
    };
    result = lowest_terms(&result);
    return result;
}