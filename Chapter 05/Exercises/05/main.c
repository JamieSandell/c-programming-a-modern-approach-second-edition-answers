/*
Is the following if statement legal?

if (n >= 1 <= 10)
    printf("n is between 1 and 10\n");

Yes, it's legal. It prints. It compares n >= 1 and then checks to see if 1 <= 10.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n = 0;
    if (n >= 1 <= 10)
    {
        printf("n is between 1 and 10\n");
    }
    return EXIT_SUCCESS;
}