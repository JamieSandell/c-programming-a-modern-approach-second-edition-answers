/*
Write a program that asks the user for a 24-hour time, then displays the time in 12-hour
form:

Enter a 24-hour time: 21:11
Equivalent  12-hour time: 9:11 PM

Be careful not to display 12:00 as 0:00.
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int hour, minute;
    printf("Enter a 24-hour time: ");
    scanf("%2d:%2d", &hour, &minute);

    bool is_pm = false;
    if (hour > 12)
    {
        is_pm = true;
        hour -= 12;
    }

    printf("Equivalent 12-hour time: %d:%.2d", hour, minute);
    (is_pm) ? printf(" PM\n") : printf(" AM\n");

    return EXIT_SUCCESS;
}