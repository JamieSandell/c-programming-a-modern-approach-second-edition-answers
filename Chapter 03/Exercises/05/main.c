/*
Suppose that we call scanf as follows: 

n = scanf("%d%f%d", &i, &x, &j); 

(i. j. and n are int variables and x is a float variable.) Assuming that the input stream 
contains the characters shown, give the values of i, j. n. and x after the call. In addition, 
indicate which characters were consumed by the call. 

(a) 10*20*30D 
i = 10, n = 1, 1 and 0 consumed by the call.
x = x, n = 0, * consumed by the call.
j = j, n = 0, * consumed by the call.

(b) 1.0*2.0*3.00 
i = 1, n = 1, 1 consumed by the call.
x = 0.1, n = 2, . and 1 consumed by the call.
j = j, n = 0, no characters consumed.

(C) 0.1*0.2*0.30 
(d) . 1* .2* .30 
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int i;
    float x;
    int j;

    n = scanf("%d%f%d", &i, &x, &j);
    printf("i = %d, n = %d, 1 and 0 consumed by the call.\n", i, n);
    printf("x = %f, n = %d, * consumed by the call.\n", x, n);
    printf("j = %d, n = %d, * consumed by the call.\n", j, n);


    return EXIT_SUCCESS;
}