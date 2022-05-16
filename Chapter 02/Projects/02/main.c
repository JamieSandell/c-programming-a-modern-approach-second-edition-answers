/*
Write a program that computes the volume of a sphere with a 10 metre radius,
using the following formula v = 4/3PirCubed. Write the faction 4/3 as 4.0f/3.0f.
(Try writing it as 4/3. What happens?) Hint: C doesn't have an exponentiation
operator, so you'll need to multiply r by itself twice to computre radius cubed.
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int radius = 10;

    float v = 4.0f / 3.0f * M_PI * radius * radius * radius;
    printf("%.2f, %s\n", v, "v = 4.0f / 3.0f * M_PI * radius * radius * radius");

    return EXIT_SUCCESS;
}