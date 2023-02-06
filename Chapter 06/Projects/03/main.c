/*
Write a program that asks the user to enter a fraction, then reduces the fraction to lowest
terms:

Enter a fraction: 6/12
In lowest terms: 1/2

Hint: To reduce a fraction to lowest terms, first compute the GCD of the numerator and
denominator. Then divide both the numerator and denominator by the GCD.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int numerator, denominator, gcd, remainder;
    int num1, num2;

    printf("Enter a fraction: ");
    scanf("%d/%d", &numerator, &denominator);
    num1 = numerator;
    num2 = denominator;

    if (num2 == 0)
    {
        gcd = num1;
    }

    while (num2 != 0)
    {
        remainder = num1 % num2;
        num1 = num2;
        num2 = remainder;
    }

    gcd = num1;
    numerator /= gcd;
    denominator /= gcd;

    printf("In lowest terms: %d/%d", numerator, denominator);

    return EXIT_SUCCESS;
}