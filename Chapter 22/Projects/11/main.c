/*
Write a program that reads a date from the command line and displays it in the following
form:

September 13, 2010
Allow the user to enter the date as either 9-13-2010 or 9/13/2010; you may assume
that there are no spaces in the date. Print an error message if the date doesn't have one of the
specified forms. Hint: Use sscanf to extract the month, day and year from the command-
line argument.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_LENGTH 255

int main(void)
{
    char buffer[MAX_BUFFER_LENGTH];

    if (fgets(buffer, MAX_BUFFER_LENGTH, stdin) == NULL)
    {
        fprintf(stderr, "Error reading user input.\n");
        return EXIT_FAILURE;
    }

    int month;
    int day;
    int year;
    const char *months[] = {
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

    if (sscanf(buffer, "%d-%d-%d", &month, &day, &year) == 3 || sscanf(buffer, "%d/%d/%d", &month, &day, &year) == 3)
    {
        printf("%s %d, %d", months[month], day, year);
    }
    else
    {
        fprintf(stderr, "Error: incorrect date format, expected mm-dd-yyyy or mm/dd/yyyy\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}