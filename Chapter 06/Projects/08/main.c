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
    int days_in_month, week_start_day;
    int current_date_of_month = 1;
    int day_of_the_week = week_start_day;

    printf("Enter number of days in month: ");
    scanf("%d", &days_in_month);
    printf("Enter starting day of the week (1=Sun, 7=Sat): ");
    scanf("%d", &week_start_day);
    
    // Print gaps until the week start day.
    if (week_start_day < 7)
    {
        for (; current_date_of_month < week_start_day; ++current_date_of_month)
        {
            if (current_date_of_month == 7)
            {
                printf("3%d\n", current_date_of_month);
            }
            else
            {
                printf("   ");
            }
        }
    }
    else if(week_start_day == 7)
    {
        printf("%21d\n", 1);
        current_date_of_month = 2;
        week_start_day = 0;
    }

    for (; current_date_of_month <= days_in_month; ++current_date_of_month, ++week_start_day)
    {
        if (week_start_day == 7)
        {
            printf("%3d\n", current_date_of_month);
            week_start_day = 0;
        }
        else
        {
            printf("%3d", current_date_of_month);
        }
    }

    return EXIT_SUCCESS;
}