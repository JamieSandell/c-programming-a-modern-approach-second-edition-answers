/*
Is the following if statement legal?

if (n == 1-10)
    printf("n is between 1 and 10\n");

If so, what does it do when n is equal to 5?

It's legal, - has greater operator precedence to ==.
if (n == (1-10))

When n is 5:
if (5 == (-9))
is false, so the print statement won't fire.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n = 5;
    
    if (n == 1 - 10)
    {
        printf("n is between 1 and 10\n");
    }

    return EXIT_SUCCESS;
}