/*
Write the following function:

unsigned int reverse_bits(unsigned int n);

reverse_bits should return an unsigned integer whose bits are the same as those in n
but in reverse order.
*/

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define TEST 1
#define UINT_BIT sizeof(unsigned int) * CHAR_BIT

unsigned int reverse_bits(unsigned int n);

int main(void)
{
    printf("%d with its bits reversed : %u\n", TEST, reverse_bits(TEST));

    return EXIT_SUCCESS;
}

unsigned int reverse_bits(unsigned int n)
{
  unsigned int reverse_num = 0; /* initialize the result*/
  unsigned int count = sizeof(unsigned int) * 8; /* counter to track the number of bits in the integer*/

  while (num != 0) {
      unsigned int last_bit = num & 1; /* get the right-most bit*/
      reverse_num <<= 1; /* add one place for the next bit */
      reverse_num |= last_bit; /* add that bit to the right-most bit of the desired reversed bits*/
      num >>= 1; /* remove one bit from the original */
      count--;
    }
  reverse_num <<= count; /* If the original bits have only 0 s then shift the remaining bits left*/
  return reverse_num;
}