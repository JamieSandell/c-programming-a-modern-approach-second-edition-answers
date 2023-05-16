/*
Write a loop that prints the highest temperature in the temperatures array (see Exercise
14) for each day of the week. The loop body should call the find_largest function,
passing it one row of the array at a time.

for (day = 0; day < DAYS; day++)
{
    day_largest = find_largest(temperatures[day], HOURS);

    printf("Day %d largest: %d\n", day, *day_largest);      
}
*/