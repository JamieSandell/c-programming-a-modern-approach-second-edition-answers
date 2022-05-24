/*
Suppose that we call scanf as follows: 

scanf("%f%d%f", &x, &i, &y);

If the user enters
12.3 45.6 789

what will be the values of x, i, and y after the call? (Assume that x and y are float
variables and i is an int variable)

x = 12.3
i = 45
y = 0.6
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    float x;
    int i;
    float y;

    scanf("%f%d%f", &x, &i, &y);
    printf("x = %f, i = %d, y = %f\n", x, i, y);

    return EXIT_SUCCESS;
}