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

int main(void)
{
    printf("Enter first date (mm/dd/yy): ");
    int first_date_mm;
    int first_date_dd;
    int first_date_yy;
    scanf("%2d/%2d/%2d", &first_date_mm, &first_date_dd, &first_date_yy);

    printf("Enter second date (mm/dd/yy): ");
    int second_date_mm;
    int second_date_dd;
    int second_date_yy;
    scanf("%2d/%2d/%2d", &second_date_mm, &second_date_dd, &second_date_yy);

    if (first_date_mm == second_date_mm && first_date_dd == second_date_dd && first_date_yy == second_date_yy)
    {
        printf("The dates are the same.\n");
        return EXIT_SUCCESS;
    }

    bool first_date_earlier;
    if (first_date_yy < second_date_yy)
    {
        first_date_earlier = true;
    }
    else if (first_date_yy > second_date_yy)
    {
        first_date_earlier = false;
    }
    else if (first_date_mm < second_date_mm)
    {
        first_date_earlier = true;
    }
    else if (first_date_mm > second_date_mm)
    {
        first_date_earlier = false;
    }
    else if (first_date_dd < second_date_dd)
    {
        first_date_earlier = true;
    }
    else
    {
        first_date_earlier = false;
    }

    if (first_date_earlier)
    {
        printf("%d/%d/%02d is earlier than %d/%d/%02d\n", first_date_mm, first_date_dd, first_date_yy,
            second_date_mm, second_date_dd, second_date_yy);
    }
    else
    {
        printf("%d/%d/%02d is earlier than %d/%d/%02d\n", second_date_mm, second_date_dd, second_date_yy,
            first_date_mm, first_date_dd, first_date_yy);
    }

    return EXIT_SUCCESS;
}