/*
Using the array of Exercise 8, write a program fragment that computes the average tempera-
ture for a month (averaged over all days of the month and all hours of the day).
*/

#include <stdio.h>
#include <stdlib.h>

#define DAYS 30
#define HOURS 24

int main(void)
{
    float temperature_readings[DAYS][HOURS] = {{0.0f}};
    float average = 0.0f;

    for (int day = 0; day < DAYS; ++day)
    {
        for (int hour = 0; hour < HOURS; ++hour)
        {
            average += temperature_readings[day][hour];
        }
    }

    average /= DAYS * HOURS;

    return EXIT_SUCCESS;
}