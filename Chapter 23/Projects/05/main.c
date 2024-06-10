/*
Suppose that money is deposited into a savings account and left for t years. Assume that the
annual interest rate is r and that interest is compounded continuously. The formula A(t) =
Pert can be used to calculate the final value of the account, where P is the original amount
deposited. For example, $1000 left on deposit for 10 years at 6% interest would be worth
$1000 x e.06 x 10 = $1000 x e.6 = $1000 x 1.8221188 = $1,822.12. Write a program that dis-
plays the result of this calculation after prompting the user to enter the original amount
deposited, the interest rate and the number of years.
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    double a, p, r;
    int t;

    printf("Enter amount deposited: ");
    scanf("%lf", &p);
    printf("Enter interest rate: ");
    scanf("%lf", &r);
    printf("Enter number of years: ");
    scanf("%d", &t);

    r /= 100.0;
    a = p * exp(r * t);

    printf("Total compounded: $ %.2lf\n", a);

    return EXIT_SUCCESS;
}