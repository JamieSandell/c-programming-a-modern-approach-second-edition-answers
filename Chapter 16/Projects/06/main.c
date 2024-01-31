/*
Modify Programming Project 9 from Chapter 5 so that each date entered by the user is
stored in a date structure (see Exercise 5). Incorporate the compare_dates function of
Exercise 5 into your program.
*/

/*
Write a program that prompts the user to enter two dates and then indicates which date
comes earlier on the calendar:

Enter first date (mm/dd/yy): 3/6/08
Enter second date (mm/dd/yy): 5/17/07
5/17/07 is earlier than 3/6/08
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct date
{
    int month;
    int day;
    int year;
};

int compare_dates(struct date d1, struct date d2);

int main(void)
{
    struct date d1, d2;

    printf("Enter first date (mm/dd/yy): ");
    scanf("%2d/%2d/%2d", &d1.month, &d1.day, &d1.year);

    printf("Enter second date (mm/dd/yy): ");
    scanf("%2d/%2d/%2d", &d2.month, &d2.day, &d2.year);

    int result = compare_dates(d1, d2);

    if (result == 0)
    {
        printf("The dates are the same.\n");
        return EXIT_SUCCESS;
    }

    if (result == -1)
    {
        printf("%d/%d/%02d is earlier than %d/%d/%02d\n", d1.month, d1.day, d1.year,
            d2.month, d2.day, d2.year);
    }
    else
    {
        printf("%d/%d/%02d is earlier than %d/%d/%02d\n", d2.month, d2.day, d2.year,
            d1.month, d1.day, d1.year);
    }

    return EXIT_SUCCESS;
}

int compare_dates(struct date d1, struct date d2)
{
    if (d1.year < d2.year)
    {
        return -1;
    }
    else if (d1.year > d2.year)
    {
        return 1;
    }

    if (d1.month < d2.month)
    {
        return -1;
    }
    else if (d1.month > d2.month)
    {
        return 1;
    }

    if (d1.day < d2.day)
    {
        return -1;
    }
    else if (d1.day > d2.day)
    {
        return 1;
    }

    return 0;
}