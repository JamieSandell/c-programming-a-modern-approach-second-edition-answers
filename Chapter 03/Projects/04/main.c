/*
Write a program that prompts the user to enter a telephone number in the form (xxx) xxx-
xxxx and then displays the number in the form xxx.xxxx.xxx:

Enter phone number [(xxx) xxx-xxxx]: (404) 817-6900
You entered 404.817.6900
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    printf("Enter phone number [(xxx) xxx-xxxx]: ");
    int beginning, middle, end;
    scanf("(%3d) %3d-%4d", &beginning, &middle, &end);
    printf("You entered %d.%d.%d\n", beginning, middle, end);

    return EXIT_SUCCESS;
}
