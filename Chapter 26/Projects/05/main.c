/*
Write a program that prompts the user to enter two dates, then prints the difference between
them, measure in days. Hint: Use the mktime and difftime functions.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BASE_YEAR 1900

time_t make_time_t(struct tm *t, int year, int month, int day);
void read_date(int *year, int *month, int *day);

int main(void)
{
    int month1;
    int day1;
    int year1;
    printf("Enter end date.\n");
    read_date(&year1, &month1, &day1);
    int month2;
    int day2;
    int year2;
    printf("Enter start date.\n");
    read_date(&year2, &month2, &day2);
    struct tm t1;
    time_t time1_info = make_time_t(&t1, year1, month1, day1);
    struct tm t2;
    time_t time2_info = make_time_t(&t2, year2, month2, day2);
    printf("Days between dates: %d\n", (int)(difftime(time1_info, time2_info) / 60/60/24));
    return EXIT_SUCCESS;
}

time_t make_time_t(struct tm *t, int year, int month, int day)
{
    t->tm_mon = month - 1;
    t->tm_mday = day;
    t->tm_year = year - BASE_YEAR;
    t->tm_sec = 0;
    t->tm_min = 0;
    t->tm_hour = -1;
    return mktime(t);
}

void read_date(int *year, int *month, int *day)
{
    printf("Enter date in yyyy-mm-dd format: ");
    scanf("%4d-%2d-%2d", year, month, day);
}