/*
In one state, single residents are subject to the following income tac:

Income          Amount of tax
Not over $750   1% of income
$750 - $2,250   $7.50   plus 2% of amount over $750
$2,250 - $3,750 $37.50  plus 3% of amount over $2,250
$3,750 - $5,250 $82.50  plus 4% of amount over $3,750
$5,250 - $7,000 $142.50 plus 5% of amount over $5,250
Over $7,000     $230.00 plus 6% of amount over $7,000
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    printf("Enter the amount of taxable income: ");
    float taxable_income;
    scanf("%2f", &taxable_income);

    float tax_due;
    float base_tax;
    float percentage_tax;
    if (taxable_income <= 750)
    {
        
    }

    return EXIT_SUCCESS;
}