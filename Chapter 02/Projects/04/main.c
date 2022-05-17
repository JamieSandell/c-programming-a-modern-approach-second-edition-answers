/*
Write a program that asks the user to enter a dollars-and-cents amount, then displays the
amount with 5% tax added:

Enter an amount:    100.00
                    -------
With tax added:     $105.00
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Enter an amount in dollars and cents: ");
    float dollars_and_cents;
    scanf("%f", &dollars_and_cents);
    printf("\n-------\n");
    printf("$%.2f\n", dollars_and_cents += dollars_and_cents / 100 * 5);
    return EXIT_SUCCESS;
}