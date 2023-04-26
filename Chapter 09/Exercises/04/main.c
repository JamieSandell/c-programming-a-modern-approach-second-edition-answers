/*
Write a function day_of_year(month, day, year) that returns the day of the year
(an integer between 1 and 366) specified by the three arguments.
*/

#include <stdlib.h>
#include <stdio.h>

int day_of_year(int month, int day, int year);

int main()
{
    int month;
    int day;
    int year;

    printf("Enter month, day, year: ");
    scanf("%d %d %d", &month, &day, &year);
    printf("Day of the year: %d\n", day_of_year(month, day, year));

    exit(EXIT_SUCCESS);
}

int day_of_year(int month, int day, int year)
{
    int days_in_month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // [0] = no month, [1] = Jan...[12] = Dec
    int day_of_year = 0;

    if (year % 4 == 0) // leap year
    {
        days_in_month[2] = 29;
    }

    for (int i = 1; i < month; i++)
    {
        day_of_year += days_in_month[i];
    }

    return day_of_year += day;
}