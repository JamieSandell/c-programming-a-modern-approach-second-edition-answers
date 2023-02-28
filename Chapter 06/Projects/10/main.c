/*
Programming project 9 in Chapter 5 asked you to write a program that determines which of
two dates comes earlier on the calendar. Generalize the program so that the user may enter
any number of dates. The user will enter 0/0/0 to indicate that no more dates will be entered:

Enter a date (mm/dd/yy): 3/6/08
Enter a date (mm/dd/yy): 5/17/07
Enter a date (mm/dd/yy): 6/3/07
Enter a date (mm/dd/yy): 0/0/0
5/17/07 is the earliest date
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int current_date_mm = 99;
    int current_date_dd = 99;
    int current_date_yy = 99;
    int previous_date_mm;
    int previous_date_dd;
    int previous_date_yy;
    int earliest_date_mm;
    int earliest_date_dd;
    int earliest_date_yy;
    bool previous_date_earlier;

    do
    {
        printf("Enter a date (mm/dd/yy): ");
        previous_date_mm = current_date_mm;
        previous_date_dd = current_date_dd;
        previous_date_yy = current_date_yy;
        scanf("%2d/%2d/%2d", &current_date_mm, &current_date_dd, &current_date_yy);

        if (previous_date_yy < current_date_yy)
        {
            previous_date_earlier = true;
        }
        else if (previous_date_yy > current_date_yy)
        {
            previous_date_earlier = false;
        }
        else if (previous_date_mm < current_date_mm)
        {
            previous_date_earlier = true;
        }
        else if (previous_date_mm > current_date_mm)
        {
            previous_date_earlier = false;
        }
        else if (previous_date_dd < current_date_dd)
        {
            previous_date_earlier = true;
        }
        else
        {
            previous_date_earlier = false;
        }

        if (previous_date_earlier)
        {
            earliest_date_mm = previous_date_mm;
            earliest_date_dd = previous_date_dd;
            earliest_date_yy = previous_date_yy;
        }

    } while (current_date_mm != 0 && current_date_dd != 0 && current_date_yy != 0);

    printf("%d/%d/%02d is the earliest date\n", earliest_date_mm, earliest_date_dd, earliest_date_yy);

    return EXIT_SUCCESS;
}