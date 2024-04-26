/*
Write the following functions:

unsigned int rotate_left(unsigned int i, int n);
unsigned int rotate_right(unsigned int i, int n);

rotate_left should return the result of shifting the bits in i to the left by n places,
with the bits that were "shifted off" moved to the right end of i (For example, the call
rotate_left(0x12345678, 4) should return 0x23456781 if integers are 32 bits
long). rotate_right is similar, but it should "rotate" bits to the right instead of the left.
*/

#include <stdio.h>
#include <stdlib.h>

#define INT_BITS sizeof(int) * 8
#define SHIFT_LEFT 4

unsigned int rotate_left(unsigned int i, int n);
unsigned int rotate_right(unsigned int i, int n);

int main(void)
{
    int number = 0x12345678; /* in binary this is:
    00010010001101000101011001111000
    shift left by 4
    00100011010001010110011110000000
    shift right by 28 (32 - 4)
    00000001001000110100010101100111

    OR
    00100011010001010110011110000000
    00000001001000110100010101100111
    =
    00100011011001110110011111100111
    */

    printf("%#04x shifted left by %d is : %#04x\n", number, SHIFT_LEFT, rotate_left(number, SHIFT_LEFT));

    return EXIT_SUCCESS;
}

unsigned int rotate_left(unsigned int i, int n)
{
    return ((i << n) | (i >> (INT_BITS - n)));
}

unsigned int rotate_right(unsigned int i, int n)
{
    return ((i >> n) | (i << (INT_BITS - n)));
}