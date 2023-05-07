/*
Modify Programming Project 7 from Chapter 2 so that it includes the following function:

void pay_amount(int dollars, int *twenties, int *tens,
                int *fives, int *ones);

The function determines the smallest number of $20, $10, $5 and $1 bills necessary to pay
the amount represented by the dollars parameter. The twenties parameter points to a
variable in which the function will store the number of $20 bills required. The tens,
fives and ones parameters are similar.
*/

/*
Write a program that asks the user to enter a U.S. dollar amount and then shows how to pay
that amount using the smallest number of $20, $10, $5, and $1 bills:

Enter a dollar amount: 93
$20 bills: 4
$10 bills: 1
 $5 bills: 0
 $1 bills : 3
*/

#include <stdio.h>
#include <stdlib.h>

void pay_amont(int dollars, int *twenties, int *tens, int *fives, int *ones);

int main()
{
    int dollar_amount;
    int twenties;
    int tens;
    int fives;
    int ones;

    printf("Enter a dollar amount: ");    
    scanf("%i", &dollar_amount);

    pay_amont(dollar_amount, &twenties, &tens, &fives, &ones);
    
    printf("\n$20 bills: %i\n", twenties);
    printf("$10 bills: %i\n", tens);
    printf(" $5 bills: %i\n", fives);
    printf(" $1 bills: %i\n", ones);

    exit(EXIT_SUCCESS);
}

void pay_amont(int dollars, int *twenties, int *tens, int *fives, int *ones)
{
    *twenties = dollars / 20;
    dollars %= 20;

    *tens = dollars/10;
    dollars %= 10;

    *fives = dollars / 5;
    dollars %= 5;

    *ones = dollars / 1;
    dollars %= 1;
}
