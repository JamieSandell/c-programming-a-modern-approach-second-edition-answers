/*
Write a program that prints a one-month calendar. The user
specifies the number of days in the month and the day of
the week on which the month begins:
    Enter number of days in month: 31
    Enter starting day of the week (1=Sun, 7=Sat): 3
            1  2  3  4  5
    6  7  8  9 10 11 12
    13 14 15 16 17 18 19
    20 21 22 23 24 25 26 
    27 28 29 30 31
Hint: This program isn't as hard as it looks. The most 
important part is a for statement that uses a variable i
to count from 1 to n, where n is the number of days in the
month, printing each value of i. Inside the loop, an if
statement tests whether i is the last day in the week; if
so, it prints a new-line character.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int days_in_month, week_start_day, date_of_first_saturday;

    printf("Enter number of days in month: ");
    scanf("%d", &days_in_month);
    printf("Enter starting day of the week (1=Sun, 7=Sat): ");
    scanf("%d", &week_start_day);
    date_of_first_saturday = 

    for (int i = 1; i < week_start_day; ++i)
    {
        if (i = 7)
        {
            printf("\n%d", i);
        }
        else
        {
            printf(" ");
        }
    }

    for (int i = 1; i < days_in_month; ++i)
    {
        if (i)
    }

    return EXIT_SUCCESS;
}