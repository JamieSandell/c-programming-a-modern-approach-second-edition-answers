/*
(a) Write the following function:

int count_ones(unsigned char ch);
count_ones should return the number of 1 bits in ch.

(b) Write the function in part (a) without using a loop.
*/

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define n 255

int count_ones(unsigned char ch);
int count_ones_no_loop(unsigned char ch);

int main(void)
{
    printf("Number of 1 bits in %d: %d\n", n, count_ones(n));
    printf("Number of 1 bits in %d: %d\n", n, count_ones_no_loop(n));

    return EXIT_SUCCESS;
}

int count_ones(unsigned char ch)
{
    int number_of_1_bits = 0;
    unsigned char mask = '\x01';

    for (int shift_amount = CHAR_BIT - 1; shift_amount >= 0; --shift_amount)
    {
        if (((ch >> shift_amount) & mask) != 0)
        {
            number_of_1_bits += ((ch >> shift_amount) & mask);
        }
        
    }

    return number_of_1_bits;
}

int count_ones_no_loop(unsigned char ch)
{
    return ((ch >> 8) & 1) + ((ch >> 7) & 1) + ((ch >> 6) & 1) + ((ch >> 5) & 1) + ((ch >> 4) & 1) + ((ch >> 3) & 1) + ((ch >> 2) & 1) + ((ch >> 1) & 1) + (ch & 1);
}