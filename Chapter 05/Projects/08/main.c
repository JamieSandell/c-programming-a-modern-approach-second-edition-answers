/*
The following table shows the daily flights from one city to another:

Departure time      Arrival time
8:00 a.m.           10:16 a.m.
9:43 a.m.           11:52 a.m.
11:19 a.m.          1:13 p.m.
12:47 p.m.          3:00 p.m.
2:00 p.m.           4:08 p.m.
3:45 p.m.           5:55 p.m.
7:00 p.m.           9:20 p.m.
9:45 p.m.           11:58 p.m.

Write a program that asks user to enter a time (expressed in hours and minutes, using the 24-hour clock).
The program then displays the departure and arrival times for the flight whose departure time is closest
to that entered by the user:

Enter a 24-hour time: 13:15
Closest departure time is 12:47 p.m., arriving at 3:00 p.m.

Hint: Convert the input into a time expressed in minutes since midnight, and compare it to
the departure times, also expressed in minutes since midnight. For example, 13:15 is 13 x
60 + 15 = 795 minutes since midnight, which is closer to 12:47 p.m. (767 minutes since midnight)
than to any of the other departure times.
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    printf("Enter a 24-hour time: ");
    int input_hours;
    int input_minutes;
    scanf("%d:%d", &input_hours, &input_minutes);
    int minutes_since_midnight = input_hours * 60 + input_minutes;

    // Store times in 24-hour clock, and convert in memory when required
    int departure_time_1_hours = 8;
    int departure_time_1_minutes = 0;
    int departure_time_1_minutes_since_midnight = departure_time_1_hours * 60 + departure_time_1_minutes;
    int arrival_time_1_hours = 10;
    int arrival_time_1_minutes = 16;
    int arrival_time_1_minutes_since_midnight = arrival_time_1_hours * 60 + arrival_time_1_minutes;    

    int departure_time_2_hours = 9;
    int departure_time_2_minutes = 43;
    int departure_time_2_minutes_since_midnight = departure_time_2_hours * 60 + departure_time_2_minutes;
    int arrival_time_2_hours = 11;
    int arrival_time_2_minutes = 52;
    int arrival_time_2_minutes_since_midnight = arrival_time_2_hours * 60 + arrival_time_2_minutes;

    int departure_time_3_hours = 11;
    int departure_time_3_minutes = 19;
    int departure_time_3_minutes_since_midnight = departure_time_3_hours * 60 + departure_time_3_minutes;
    int arrival_time_3_hours = 13;
    int arrival_time_3_minutes = 13;
    int arrival_time_3_minutes_since_midnight = arrival_time_3_hours * 60 + arrival_time_3_minutes;

    int departure_time_4_hours = 12;
    int departure_time_4_minutes = 47;
    int departure_time_4_minutes_since_midnight = departure_time_4_hours * 60 + departure_time_4_minutes;
    int arrival_time_4_hours = 15;
    int arrival_time_4_minutes = 0;
    int arrival_time_4_minutes_since_midnight = arrival_time_4_hours * 60 + arrival_time_4_minutes;

    int departure_time_5_hours = 14;
    int departure_time_5_minutes = 0;
    int departure_time_5_minutes_since_midnight = departure_time_5_hours * 60 + departure_time_5_minutes;
    int arrival_time_5_hours = 16;
    int arrival_time_5_minutes = 8;
    int arrival_time_5_minutes_since_midnight = arrival_time_5_hours * 60 + arrival_time_5_minutes;

    int departure_time_6_hours = 15;
    int departure_time_6_minutes = 45;
    int departure_time_6_minutes_since_midnight = departure_time_6_hours * 60 + departure_time_6_minutes;
    int arrival_time_6_hours = 17;
    int arrival_time_6_minutes = 55;
    int arrival_time_6_minutes_since_midnight = arrival_time_6_hours * 60 + arrival_time_6_minutes;

    int departure_time_7_hours = 19;
    int departure_time_7_minutes = 00;
    int departure_time_7_minutes_since_midnight = departure_time_7_hours * 60 + departure_time_7_minutes;
    int arrival_time_7_hours = 21;
    int arrival_time_7_minutes = 20;
    int arrival_time_7_minutes_since_midnight = arrival_time_7_hours * 60 + arrival_time_7_minutes;

    int departure_time_8_hours = 21;
    int departure_time_8_minutes = 45;
    int departure_time_8_minutes_since_midnight = departure_time_8_hours * 60 + departure_time_8_minutes;
    int arrival_time_8_hours = 23;
    int arrival_time_8_minutes = 58;
    int arrival_time_8_minutes_since_midnight = arrival_time_8_hours * 60 + arrival_time_8_minutes;

    // calculate the closest departure date to the user's input
    int absolute_difference = abs(minutes_since_midnight - departure_time_1_minutes_since_midnight);
    int closest_match_in_minutes_since_midnight_departure_time = departure_time_1_minutes_since_midnight;
    int closest_match_in_minutes_since_midnight_arrival_time = arrival_time_1_minutes_since_midnight;
    bool closest_match_found = false;
    int smallest_absolute_difference = absolute_difference;
    if (absolute_difference  == 0)
    {
        closest_match_found = true;
    }
    if (!closest_match_found)
    {
        absolute_difference = abs(minutes_since_midnight - departure_time_2_minutes_since_midnight);
        if (absolute_difference == 0)
        {
            closest_match_in_minutes_since_midnight_departure_time = departure_time_2_minutes_since_midnight;
            closest_match_in_minutes_since_midnight_arrival_time = arrival_time_2_minutes_since_midnight;
            closest_match_found = true;
        }
        else if(absolute_difference < smallest_absolute_difference)
        {
            smallest_absolute_difference = absolute_difference;
            closest_match_in_minutes_since_midnight_departure_time = departure_time_2_minutes_since_midnight;
            closest_match_in_minutes_since_midnight_arrival_time = arrival_time_2_minutes_since_midnight;
        }
    }
    if (!closest_match_found)
    {
        absolute_difference = abs(minutes_since_midnight - departure_time_3_minutes_since_midnight);
        if (absolute_difference == 0)
        {
            closest_match_in_minutes_since_midnight_departure_time = departure_time_3_minutes_since_midnight;
            closest_match_in_minutes_since_midnight_arrival_time = arrival_time_3_minutes_since_midnight;
            closest_match_found = true;
        }
        else if(absolute_difference < smallest_absolute_difference)
        {
            smallest_absolute_difference = absolute_difference;
            closest_match_in_minutes_since_midnight_departure_time = departure_time_3_minutes_since_midnight;
            closest_match_in_minutes_since_midnight_arrival_time = arrival_time_3_minutes_since_midnight;
        }
    }
    if (!closest_match_found)
    {
        absolute_difference = abs(minutes_since_midnight - departure_time_4_minutes_since_midnight);
        if (absolute_difference == 0)
        {
            closest_match_in_minutes_since_midnight_departure_time = departure_time_4_minutes_since_midnight;
            closest_match_in_minutes_since_midnight_arrival_time = arrival_time_4_minutes_since_midnight;
            closest_match_found = true;
        }
        else if(absolute_difference < smallest_absolute_difference)
        {
            smallest_absolute_difference = absolute_difference;
            closest_match_in_minutes_since_midnight_departure_time = departure_time_4_minutes_since_midnight;
            closest_match_in_minutes_since_midnight_arrival_time = arrival_time_4_minutes_since_midnight;
        }
    }
    if (!closest_match_found)
    {
        absolute_difference = abs(minutes_since_midnight - departure_time_5_minutes_since_midnight);
        if (absolute_difference == 0)
        {
            closest_match_in_minutes_since_midnight_departure_time = departure_time_5_minutes_since_midnight;
            closest_match_in_minutes_since_midnight_arrival_time = arrival_time_5_minutes_since_midnight;
            closest_match_found = true;
        }
        else if(absolute_difference < smallest_absolute_difference)
        {
            smallest_absolute_difference = absolute_difference;
            closest_match_in_minutes_since_midnight_departure_time = departure_time_5_minutes_since_midnight;
            closest_match_in_minutes_since_midnight_arrival_time = arrival_time_5_minutes_since_midnight;
        }
    }
    if (!closest_match_found)
    {
        absolute_difference = abs(minutes_since_midnight - departure_time_6_minutes_since_midnight);
        if (absolute_difference == 0)
        {
            closest_match_in_minutes_since_midnight_departure_time = departure_time_6_minutes_since_midnight;
            closest_match_in_minutes_since_midnight_arrival_time = arrival_time_6_minutes_since_midnight;
            closest_match_found = true;
        }
        else if(absolute_difference < smallest_absolute_difference)
        {
            smallest_absolute_difference = absolute_difference;
            closest_match_in_minutes_since_midnight_departure_time = departure_time_6_minutes_since_midnight;
            closest_match_in_minutes_since_midnight_arrival_time = arrival_time_6_minutes_since_midnight;
        }
    }
    if (!closest_match_found)
    {
        absolute_difference = abs(minutes_since_midnight - departure_time_7_minutes_since_midnight);
        if (absolute_difference == 0)
        {
            closest_match_in_minutes_since_midnight_departure_time = departure_time_7_minutes_since_midnight;
            closest_match_in_minutes_since_midnight_arrival_time = arrival_time_7_minutes_since_midnight;
            closest_match_found = true;
        }
        else if(absolute_difference < smallest_absolute_difference)
        {
            smallest_absolute_difference = absolute_difference;
            closest_match_in_minutes_since_midnight_departure_time = departure_time_7_minutes_since_midnight;
            closest_match_in_minutes_since_midnight_arrival_time = arrival_time_7_minutes_since_midnight;
        }
    }
    if (!closest_match_found)
    {
        absolute_difference = abs(minutes_since_midnight - departure_time_8_minutes_since_midnight);
        if (absolute_difference == 0)
        {
            closest_match_in_minutes_since_midnight_departure_time = departure_time_8_minutes_since_midnight;
            closest_match_in_minutes_since_midnight_arrival_time = arrival_time_8_minutes_since_midnight;
            closest_match_found = true;
        }
        else if(absolute_difference < smallest_absolute_difference)
        {
            smallest_absolute_difference = absolute_difference;
            closest_match_in_minutes_since_midnight_departure_time = departure_time_8_minutes_since_midnight;
            closest_match_in_minutes_since_midnight_arrival_time = arrival_time_8_minutes_since_midnight;
        }
    }
    // output the result
    int departure_time_hours_in_12_hour_format = closest_match_in_minutes_since_midnight_departure_time / 60;
    bool departure_time_is_am = true;
    if (departure_time_hours_in_12_hour_format > 12)
    {
        departure_time_hours_in_12_hour_format -= 12;
        departure_time_is_am = false;
    }
    int minutes = closest_match_in_minutes_since_midnight_departure_time % 60;
    printf("Closest departure time is %d:%.2d ", departure_time_hours_in_12_hour_format, minutes);
    if (departure_time_is_am)
    {
        printf("a.m.");
    }
    else
    {
        printf("p.m.");
    }
    int arrival_time_hours_in_12_hour_format = closest_match_in_minutes_since_midnight_arrival_time / 60;
    bool arrival_time_is_am = true;
    if (arrival_time_hours_in_12_hour_format > 12)
    {
        arrival_time_hours_in_12_hour_format -= 12;
        arrival_time_is_am = false;
    }
    minutes = closest_match_in_minutes_since_midnight_arrival_time % 60;
    printf(", arriving at %d:%.2d ", arrival_time_hours_in_12_hour_format, minutes);
    if (arrival_time_is_am)
    {
        printf("a.m.\n");
    }
    else
    {
        printf("p.m.\n");
    }

    return EXIT_SUCCESS;
}