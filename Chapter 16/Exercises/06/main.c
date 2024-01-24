/*
Write the following function, assuming that the time structure contains three members:
hours, minutes and seconds (all of type int).

struct time split_time(long total_seconds);

total_seconds is a time represented as the number of seconds since midnight.
The function returns a structure containing the equivalent time in hours (0-23), minutes (0-59),
and seconds (0-59).
*/

#include <stdlib.h>

struct time
{
    int hours;
    int minutes;
    int seconds;
};

struct time split_time(long total_seconds);

int main(void)
{
    return EXIT_SUCCESS;
}

struct time split_time(long total_seconds)
{
    struct time result =
    {
        .hours = (total_seconds / 3600),
        .minutes = (total_seconds - (3600 * (total_seconds / 3600)) / 60),
        .seconds = (total_seconds - (3600 * (total_seconds / 3600)) - ((total_seconds - (3600 * (total_seconds / 3600)) / 60)) * 60)
    };

    return result;
}