/*
Here's a simplified version of the Beaufort scale, which is used to estimate wind force:

Speed (knots)   Description
Less than 1     Calm
1 - 3           Light air
4 - 27          Breeze
28 - 47         Gale
48 - 63         Storm
Above 63        Hurricane

Write a program that asks the user to enter a wind speed (in knots), then displays the corre-
sponding description.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    printf("Enter a wind speec (in knots): ");
    int wind_speed_in_knots;
    scanf("%d", &wind_speed_in_knots);

    if (wind_speed_in_knots < 1)
    {
        printf("Calm\n");
    }
    else if(wind_speed_in_knots >= 1 && wind_speed_in_knots <= 3)
    {
        printf("Light air\n");
    }
    else if(wind_speed_in_knots >= 4 && wind_speed_in_knots <= 27)
    {
        printf("Breeze\n");
    }
    else if(wind_speed_in_knots >= 28 && wind_speed_in_knots <= 47)
    {
        printf("Gale\n");
    }
    else if(wind_speed_in_knots >= 48 && wind_speed_in_knots <= 63)
    {
        printf("Storm\n");
    }
    else
    {
        printf("Hurricane\n");
    }

    return EXIT_SUCCESS;
}