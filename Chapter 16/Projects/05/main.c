/*
Modify Programming Project 8 from Chapter 5 so that the times are stored in a single array.
The elements of the array will be structures, each containing a departure time and the corre-
sponding arrival time. (Each time will be an integer, representing the number of minutes)
since midnight.) The program will use a loop to search the array for the departure time clos-
est to the time entered by the user.
*/

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

#define NUMBER_OF_TIMES 8

struct time
{
    int departure_time;
    int arrival_time;
};

int main(void)
{
    struct time times[NUMBER_OF_TIMES] = 
    {
        {.departure_time = 480, .arrival_time = 616},
        {.departure_time = 583, .arrival_time = 712},
        {.departure_time = 679, .arrival_time = 793},
        {.departure_time = 767, .arrival_time = 900},
        {.departure_time = 840, .arrival_time = 968},
        {.departure_time = 945, .arrival_time = 1075},
        {.departure_time = 1140, .arrival_time = 1280},
        {.departure_time = 1305, .arrival_time = 1438}
    };

    printf("Enter a 24-hour time: ");
    int input_hours;
    int input_minutes;
    scanf("%d:%d", &input_hours, &input_minutes);
    int minutes_since_midnight = input_hours * 60 + input_minutes;

    // calculate the closest departure date to the user's input
    int absolute_difference = abs(minutes_since_midnight - times[1].departure_time);
    int smallest_absolute_difference = absolute_difference;
    int result;

    for (int i = 1; i < NUMBER_OF_TIMES; ++i)
    {
        absolute_difference = abs(minutes_since_midnight - times[i].departure_time);

        if (absolute_difference == 0)
        {
            result = i;
            break;
        }
        else if(absolute_difference < smallest_absolute_difference)
        {
            result = i;
            smallest_absolute_difference = absolute_difference;
        }
    }

    // output the result
    int departure_time_hours_in_12_hour_format = times[result].departure_time / 60;
    bool departure_time_is_am = true;

    if (departure_time_hours_in_12_hour_format > 12)
    {
        departure_time_hours_in_12_hour_format -= 12;
        departure_time_is_am = false;
    }
    else if(departure_time_hours_in_12_hour_format == 12)
    {
        departure_time_is_am = false;
    }

    int minutes = times[result].departure_time % 60;
    printf("Closest departure time is %d:%.2d ", departure_time_hours_in_12_hour_format, minutes);

    if (departure_time_is_am)
    {
        printf("a.m.");
    }
    else
    {
        printf("p.m.");
    }

    int arrival_time_hours_in_12_hour_format = times[result].arrival_time / 60;
    bool arrival_time_is_am = true;

    if (arrival_time_hours_in_12_hour_format > 12)
    {
        arrival_time_hours_in_12_hour_format -= 12;
        arrival_time_is_am = false;
    }
    else if(arrival_time_hours_in_12_hour_format == 12)
    {
        arrival_time_is_am = false;
    }

    minutes = times[result].arrival_time % 60;
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