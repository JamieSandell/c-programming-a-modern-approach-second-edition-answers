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

int main()
{
    printf("Enter a dollar amount: ");
    int dollar_amount;
    scanf("%i", &dollar_amount);
    int twenty_bills = dollar_amount / 20;
    dollar_amount = dollar_amount % 20;
    int ten_bills = dollar_amount / 10;
    dollar_amount = dollar_amount % 10;
    int five_bills = dollar_amount / 5;
    dollar_amount = dollar_amount % 5;
    int one_bills = dollar_amount;
    printf("\n$20 bills: %i\n", twenty_bills);
    printf("$10 bills: %i\n", ten_bills);
    printf(" $5 bills: %i\n", five_bills);
    printf(" $1 bills: %i\n", one_bills);

    return EXIT_SUCCESS;
}