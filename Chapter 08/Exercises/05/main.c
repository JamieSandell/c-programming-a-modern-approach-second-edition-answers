/*
The Fibonacci numbers are 0, 1, 1, 2, 3, 5, 8, 13, ..., where each number is the sum of the
two preceding numbers. Write a program fragment that declares an array named fib_numbers
of length 40 and fills the array with the first 40 Fibonacci numbers. Hint:
Fill in the first two numbers individually, then use a loop to compute the remaining numbers.
*/

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 40

int main(void)
{
    int fib_numbers[ARRAY_SIZE] = {[0] = 0, [1] = 1};

    for (int i = 0; i < 2; ++i)
    {
        printf("%d ", fib_numbers[i]);
    }

    for (int i = 2; i < ARRAY_SIZE; ++i)
    {
        fib_numbers[i] = fib_numbers[i - 1] + fib_numbers[i - 2];
        printf("%d ", fib_numbers[i]);
    }
    printf("\n");

    return EXIT_SUCCESS;
}