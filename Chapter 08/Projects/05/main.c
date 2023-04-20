/*
Modify the interest.c program of Section 8.1 so that it compound interest monthly
instead of annually. The form of the output shouldn't change: the balance should still be
shown at annual intervals.
*/

#include <stdio.h>
#include <stdlib.h>

#define NUM_RATES ((int) (sizeof(value) / sizeof(value[0])))
#define INITIAL_BALANCE 100.00

int main(void)
{
    int low_rate, num_years;
    double value[5];

    printf("Enter interest rate: ");
    scanf("%d", &low_rate);
    printf("Enter number of years: ");
    scanf("%d", &num_years);

    printf("\nYears");
    for (int i = 0; i < NUM_RATES; i++)
    {
        printf("%6d%%", low_rate + i);
        value[i] = INITIAL_BALANCE;
    }
    printf("\n");

    for (int year = 1; year <= num_years; year++)
    {
        printf("%3d     ", year);
    }

    return EXIT_SUCCESS;
}