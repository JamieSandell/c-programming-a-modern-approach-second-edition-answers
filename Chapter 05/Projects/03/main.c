/*
Modify the broker.c program of Section 5.2 by making both of the following changes:
(a) Ask the user to enter the number of shares and the price per share, instead of the value
of the trade.
(b) Add statements that compute the commission charged by a rival broker ($33 plus 3c per
share for fewer than 2000 shares; $33 plus 2c per share for 2000 shares or more). Dis-
play the rival's commission as well as the commission charged by the original broker.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    float commission;
    int number_of_shares;
    float price_per_share;

    printf("Enter the number of shares and the price per share: ");
    scanf("%d %f", &number_of_shares, &price_per_share);
    float value = number_of_shares * price_per_share;

    float rival_broker_commission;
    if (value < 2000.00f)
    {
        commission = 30.0f + .017f * value;
        rival_broker_commission = 33.0f + 0.03f * value;
    }
    else if (value < 2500.00f)
    {
        commission = 30.0f + .017f * value;
        rival_broker_commission = 33.0f + 0.02f * value;
    }
    else if (value < 6250.00f)
    {
        commission = 56.00f + .0066f * value;
        rival_broker_commission = 33.0f + 0.02f * value;
    }
    else if (value < 20000.00f)
    {
        commission = 76.00f + .0034 * value;
        rival_broker_commission = 33.0f + 0.02f * value;
    }
    else if (value < 50000.00f)
    {
        commission = 100.00f + .0022f * value;
        rival_broker_commission = 33.0f + 0.02f * value;
    }
    else if (value < 50000000.00f)
    {
        commission = 155.00f + .0011f * value;
        rival_broker_commission = 33.0f + 0.02f * value;
    }
    else
    {
        commission = 255.00f + .0009f * value;
        rival_broker_commission = 33.0f + 0.02f * value;
    }

    if (commission < 39.00f)
    {
        commission = 39.00f;
        rival_broker_commission = 39.00f;
    }

    printf("Commission: $%.2f\n", commission);
    printf("Rival Commission: $%.2f\n", rival_broker_commission);

    return EXIT_SUCCESS;
}