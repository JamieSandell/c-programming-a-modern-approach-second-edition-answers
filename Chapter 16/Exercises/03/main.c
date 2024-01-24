/*
(a) Show how to declare a tag named complex for a structure with two members, real
and imaginary, of type double.

(b) Use the complex tag to declare variables named c1, c2 and c3.

(c) Write a function named make_complex that stores its two arguments (both of type
double) in a complex structure, then returns the structure.

(d) Write a function named add_complex that adds the corresponding members of its
arguments (both complex structures), then returns the result (another complex structure).
*/

#include <stdlib.h>

struct complex // (a)
{
    double real;
    double imaginary;
};

struct complex make_complex(double real, double imaginary);
struct complex add_complex(struct complex a, struct complex b);

int main(void)
{
    

    struct complex c1, c2, c3; // (b)

    return EXIT_SUCCESS;
}

struct complex make_complex(double real, double imaginary) // (c)
{
    struct complex make = {.real = real, .imaginary = imaginary};
    return make;
}

struct complex add_complex(struct complex a, struct complex b) // (d)
{
    struct complex result = {.real = a.real + b.real, .imaginary = a.imaginary + b.imaginary};
    return result;
}