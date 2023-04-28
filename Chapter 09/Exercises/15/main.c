/*
The following (rather confusing) function finds the median of three numbers. Rewrite the
function so that it has just one return statement.

double median(double x, double y, double z)
{
    if (x <= y)
        if (y <= z) return y;
        else if (x <= z return z;
        else return x;
    if (z <= y) return y;
    if (x <= z) return x;
    return z;
}
*/

#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#define LENGTH 3

double median(double x, double y, double z);

int main(void)
{
    printf("Median of 10.0 17.5 4.5: %.1f\n", median(10.0, 17.5, 4.5));

    exit(EXIT_SUCCESS);
}

double median(double x, double y, double z)
{
    return fmax(fmin(fmax(x, y), z), fmin(x, fmax(y, z)));
}