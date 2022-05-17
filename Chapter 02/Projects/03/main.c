/*
Modify the program of Programming Project 2 so that it prompts the user to enter the radius
of the sphere.
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Enter the radius of the sphere: ");
    float radius;
    scanf("%f", &radius);

    float v = 4.0f / 3.0f * M_PI * radius * radius * radius;
    printf("%.2f, %s\n", v, "v = 4.0f / 3.0f * M_PI * radius * radius * radius");

    return EXIT_SUCCESS;
}