/*
Use typedef to create types names Int8, Int16, and Int32. Define the types so that
they represent 8-bit, 16-bit and 32-bit integers on your machine.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    typedef char Int8;
    typedef short Int16;
    typedef int Int32;

    Int8 eight_bits = 125;
    Int16 sixteen_bits = 1333;
    Int32 thirty_two_bits = 83838;

    printf("%d %d %d\n", eight_bits, sixteen_bits, thirty_two_bits);

    return EXIT_SUCCESS;
}