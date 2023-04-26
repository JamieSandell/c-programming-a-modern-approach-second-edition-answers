/*
Write a function num_digits(n) that returns the number of digits in n (a positive inte-
ger). Hint: To determine the number of digits in a number n, divide it by 10 repeatedly.
When n reaches 0, the number of divisions indicates how many digits n originally had.
*/

#include <stdlib.h>
#include <stdio.h>

unsigned int num_digits(unsigned int n);

int main()
{
    unsigned int n;

    printf("Enter a positive number: ");
    scanf("%u", &n);
    printf("Numbr of digits: %u\n", num_digits(n));

    exit(EXIT_SUCCESS);
}

unsigned int num_digits(unsigned int n)
{
    int count = 0;

    while (n != 0)
    {
        n /= 10;
        count++;
    }

    return count;
}