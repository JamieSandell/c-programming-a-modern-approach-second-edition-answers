/*
Add a loop to the broker.c program of Section 5.2 so that the user can enter more than
one trade and the program will calculate the commission on each. The program should ter-
minate when the user enters 0 as the trade value:

Enter value of trade: 30000
Commission: $166.00

Enter value of trade: 20000
Commission: $144.00

Enter value of trade: 0
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    float commission, value;

    while (true)
    {
        printf("Enter value of trade: ");
        scanf("%f", &value);
        if (value == 0)
        {
            break;
        }

        if (value < 2500.0f)
        {
            commission = 30.00f + 0.017f * value;
        }
        else if (value < 6250.00f)
        {
            commission = 56.00f + 0.0066f * value;
        }
        else if (value < 20000.00f)
        {
            commission = 76.00f + 0.0034f * value;
        }
        else if (value < 50000.00f)
        {
            commission = 100.00f + 0.0022f * value;
        }
        else if (value < 500000.00f)
        {
            commission = 155.00f + 0.0011f * value;
        }
        else
        {
            commission = 255.00f + 0.0009f * value;
        }

        if (commission < 39.00f)
        {
            commission = 39.00f;
        }

        printf("Commission: $%.2f\n", commission);
    }

    

    return EXIT_SUCCESS;
}