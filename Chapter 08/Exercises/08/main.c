/*
Write a declaration for a two-dimensional array named temperature_readings that
stores one month of hourly temperature readings. (For simplicity, assume that a month has
30 days.) The rows of the array should represent days of the month; the colums should rep-
resent hours of the day.
*/

#include <stdio.h>
#include <stdlib.h>

#define DAYS 30
#define HOURS 24

int main(void)
{
    float temperature_readings[DAYS][HOURS] = {{0.0f}};

    for (int day = 0; day < DAYS; ++day)
    {
        for (int hour = 0; hour < HOURS; ++hour)
        {
            printf("%f\n", temperature_readings[day][hour]);
        }
    }

    return EXIT_SUCCESS;
}