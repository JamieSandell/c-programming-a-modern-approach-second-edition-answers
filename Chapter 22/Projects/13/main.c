/*
Modify Programming Project 8 from Chapter 5 so that the program obtains departure and
arrival times from a file named flights.dat. Each line of the file will contain a depar-
ture time followed by an arrival time, with one or more spaces separating the two. Times
will be expressed using the 24-hour clock. For example, here's what flights.dat might
look like if it contained the flight information listed in the original project:

8:00 10:16
9:43 11:52
11:19 13:31
12:47 15:00
14:00 16:08
15:45 17:55
19:00 12:20
21:45 23:58
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

#define MAX_FILE_SIZE 1024
#define MAX_MESSAGE_SIZE 512

struct flight_time
{
    int departure_time_hours;
    int departure_time_minutes;
    int departure_time_minutes_since_midnight;
    int arrival_time_hours;
    int arrival_time_minutes;
    int arrival_time_minutes_since_midnight;
    struct flight_time *next;
};

void find_closest_flight(int desired_time, int *departure_time, int *arrival_time);
void terminate(bool condition, const char *message);

int main(int argc, char *argv[])
{
    char message[MAX_MESSAGE_SIZE];
    snprintf(message, MAX_MESSAGE_SIZE, "Incorrect usage, expected usage: flights.dat\n");
    terminate(argc != 2, message);

    FILE *fpr = fopen(argv[1], "rb");
    snprintf(message, MAX_MESSAGE_SIZE, "Error opening %s for reading.\n", argv[1]);
    terminate(fpr == NULL, message);

    snprintf(message, MAX_MESSAGE_SIZE, "Error seeking to the end of %s\n", argv[1]);
    terminate(fseek(fpr, 0L, SEEK_END), message);

    long file_size = ftell(fpr);
    snprintf(message, MAX_MESSAGE_SIZE, "Error getting file size of %s\n", argv[1]);
    terminate(file_size == -1L, message);

    snprintf(message, MAX_MESSAGE_SIZE, "Error, %s is too big for the buffer. %ld vs %d\n", argv[1], file_size, MAX_FILE_SIZE);
    terminate(file_size > MAX_FILE_SIZE, message);

    snprintf(message, MAX_MESSAGE_SIZE, "Error seeking to the beginning of %s\n", argv[1]);
    terminate(seek(fpr, 0L, SEEK_SET), message);

    char file_contents[MAX_FILE_SIZE];
    snprintf(message, MAX_MESSAGE_SIZE, "Error reading the contents of %s\n", argv[1]);
    terminate(fread(file_contents, MAX_FILE_SIZE, 1, fpr) != file_size, message);

    int departure_time_hours;
    int departure_time_minutes;
    int arrival_time_hours;
    int arrival_time_minutes;
    struct flight_time *head = NULL;

    while (scanf(" %d:%d %d:%d ", &departure_time_hours, &departure_time_minutes, &arrival_time_hours, &arrival_time_minutes) == 4)
    {
        struct flight_time *new_node = malloc(sizeof(struct flight_time));
        snprintf(message, MAX_MESSAGE_SIZE, "Error allocating memory.\n");
        terminate(new_node == NULL, message);

        new_node->departure_time_hours = departure_time_hours;
        new_node->departure_time_minutes = departure_time_minutes;
        new_node->departure_time_minutes_since_midnight = departure_time_hours * 60 + departure_time_minutes;
        new_node->arrival_time_hours = arrival_time_hours;
        new_node->arrival_time_minutes = arrival_time_minutes;
        new_node->arrival_time_minutes_since_midnight = arrival_time_hours * 60 + arrival_time_minutes;
        new_node->next = NULL; 

        if (head == NULL)
        {
            head = new_node;
            continue;
        }

        struct flight_time *last = head;

        while (last->next != NULL)
        {
            last = last->next;
        }

        last->next = new_node;        
    }

    snprintf(message, MAX_MESSAGE_SIZE, "Error head is NULL.\n");
    terminate(head == NULL, message);

    printf("Enter a 24-hour time: ");
    int input_hours;
    int input_minutes;
    
    snprintf(message, MAX_MESSAGE_SIZE, "Error: User input in an incorrect format. Expected hh:mm\n");
    terminate(scanf("%d:%d", &input_hours, &input_minutes) !=2, message);

    int minutes_since_midnight = input_hours * 60 + input_minutes;
    struct flight_time *current = head;
    bool closest_match_found = false;
    int absolute_difference;
    int closest_match_in_minutes_since_midnight_departure_time;
    int closest_match_in_minutes_since_midnight_arrival_time;
    closest_match_found = false;
    int smallest_absolute_difference;

    while (current != NULL)
    {
        current = current->next;
        absolute_difference = abs(minutes_since_midnight - current->departure_time_minutes_since_midnight);
        closest_match_in_minutes_since_midnight_departure_time = current->departure_time_minutes_since_midnight;
        closest_match_in_minutes_since_midnight_arrival_time = current->arrival_time_minutes_since_midnight;
        closest_match_found = false;
        smallest_absolute_difference = absolute_difference;
    }
    
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

void terminate(bool condition, const char *message)
{
    if (condition)
    {
        fprintf(stderr, "%s", message);
        exit(EXIT_FAILURE);
    }
}