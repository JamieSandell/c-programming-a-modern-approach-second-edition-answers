/*
Write a program that accepts a date from the user in the form mm/dd/yyyy and then dis-
plays it in the form month dd, yyyy, where month is the name of the month:

Enter a date (mm/dd/yyyy): 2/17/2011
You entered the date February 17, 2011

Store the month names in an array that contains pointers to string.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const char *months[] =
    {
        "",
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"
    };
    int month;
    int day;
    int year;

    printf("Enter a date (mm/dd/yyy): ");
    scanf("%2d/%2d/%4d", &month, &day, &year);
    printf("You entered the date %s %2d, %4d", months[month], day, year);

    exit(EXIT_SUCCESS);
}