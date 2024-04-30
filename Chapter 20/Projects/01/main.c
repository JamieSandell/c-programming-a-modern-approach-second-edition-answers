/*
Design a union that makes it possible to view a 32-bit value as either a float or the struc-
ture described in Exercise 14. Write a program that stores 1 in the structure's sign field, 128
in the exponent field and 0 in the fraction field, then prints the float value stored in the
union (The answer should be -2.0 if you've set up the bit-fields correctly).
*/

#include <stdio.h>
#include <stdlib.h>

union my_float
{
    float built_in_float;
    struct float_value
    {
        unsigned int fraction : 23;
        unsigned int exponent : 8;
        unsigned int sign : 1;
    };
};

int main(void)
{
    union my_float number;
    number.sign = 1;
    number.exponent = 128;
    number.fraction = 0;

    printf("%.1f\n", number.built_in_float);

    return EXIT_SUCCESS;
}