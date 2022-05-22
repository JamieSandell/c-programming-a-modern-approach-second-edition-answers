/*
Suppose that we call scanf as follows; 
scanf("%d%f%d, &i, &x, &j) ; 

If the user enters 

10.3 5 6 

what will be the values of i. x. and j after the call? (Assume that i and j are int variables 
and x is a float variable.)

i = 10
x = 0.3
j = 5
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    float x;
    int j;

    scanf("%d%f%d", &i, &x, &j);
    printf("%d %f %d\n", i, x, j);

    return EXIT_SUCCESS;
}