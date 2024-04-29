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
  unsigned int reversed = 0;
  unsigned int bit_mask = 0x01;
  unsigned int get_bit;
  unsigned int shift_left_modifier = 0;

  /*
  grab the bit at the right most end (inc along each time, so if the first time it's bit 8 next time will be bit 7)
  shift it into position and create a bit mask with it
  OR that with reversed
  */
  for (int i = 0; i < UINT_BIT; ++i)
  {
    get_bit = (n >> (UINT_BIT - i - 1)) & bit_mask; // shift the bit all the way to the right and then see if it's a 1 or 0 by anding it with our bit mask of 0x01.
    reversed |= (get_bit << shift_left_modifier); // shift the bit into position and then OR it with reversed to place it in.
    ++shift_left_modifier;
  }

  return reversed;
}