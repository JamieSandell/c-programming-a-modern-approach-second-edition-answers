/*
Write a program that prompts the user for a date (month, day and year) and an integer n,
then prints the date that's n days later.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    printf("Enter date in mm-dd-yyyy format: ");
    int month;
    int day;
    int year;
    scanf("%2d-%2d-%4d", &month, &day, &year);
    printf("Enter n days later: ");
    int n;
    scanf("%d", &n);
    struct tm t;
    t.tm_mon = month - 1;
    t.tm_mday = day + n;
    t.tm_year = year - 1900;
    time_t time_info = mktime(&t);
    time_info = localtime(&t);
    printf("%s", asctime(time_info));

    return EXIT_SUCCESS;
}