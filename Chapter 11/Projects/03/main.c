/*
Modify Programming Project 3 from Chapter 6 so that it includes the following function:

void reduce(int numerator, int denominator,
            int *reduced_numerator,
            int *reduced_denominator);

numerator and denominator are the numerator and denominator of a fraction.
reduced_numerator and reduced_denominator are pointers to variables in
which the function will store the numerator and denominator of the fraction once it has been
reduced to lowest terms.
*/

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

void reduce(int numerator, int denominator, int *reduced_numerator, int *reduced_denominator);

int main(void)
{
    int numerator, denominator;

    printf("Enter a fraction: ");
    scanf("%d/%d", &numerator, &denominator);
    reduce(numerator, denominator, &numerator, &denominator);
    printf("In lowest terms: %d/%d\n", numerator, denominator);

    exit(EXIT_SUCCESS);
}

void reduce(int numerator, int denominator, int *reduced_numerator, int *reduced_denominator)
{
    int gcd;
    int remainder;

    if (numerator == 0)
    {
        gcd = numerator;
    }

    while (denominator != 0)
    {
        remainder = numerator % denominator;
        numerator = denominator;
        denominator = remainder;
    }

    gcd = numerator;
    *reduced_numerator /= gcd;
    *reduced_denominator /= gcd;
}