/*
Modify Programming Project 5 from Chapter 5 so that it uses a function to compute the
amount of income tax. When passed an amount of taxable income, the function will return
the tax due.
*/

/*
In one state, single residents are subject to the following income tax:

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

float compute_tax_due(float taxable_income);

int main(void)
{
    float taxable_income;

    printf("Enter the amount of taxable income: ");    
    scanf("%2f", &taxable_income);
    printf("Tax due: $%.2f\n", compute_tax_due(taxable_income));

    exit(EXIT_SUCCESS);
}

float compute_tax_due(float taxable_income)
{
    float base_tax;
    float over_amount;
    int percentage_tax;

    if (taxable_income <= 750)
    {
        base_tax = 0.01f * taxable_income;
        percentage_tax = 0;
        over_amount = 0;
    }
    else if (taxable_income <= 2250)
    {
        base_tax = 7.50f;
        percentage_tax = 0.02f;
        over_amount = 750.00f;
    }
    else if(taxable_income <= 3750)
    {
        base_tax = 37.50f;
        percentage_tax = 0.03f;
        over_amount = 2250.00f;
    }
    else if (taxable_income <= 5250)
    {
        base_tax = 82.50f;
        percentage_tax = 0.04f;
        over_amount = 3750.00f;
    }
    else if (taxable_income <= 7000)
    {
        base_tax = 142.50f;
        percentage_tax = 0.05f;
        over_amount = 5250.00f;
    }
    else
    {
        base_tax = 230.00f;
        percentage_tax = 0.06f;
        over_amount = 5250.00f;
    }

    return base_tax + (percentage_tax * (taxable_income - over_amount));
}