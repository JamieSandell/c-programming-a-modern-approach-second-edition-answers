/*
Programming Project 8 in Chapter 2 asked you to write a program that calculates the
remaining balance on a loan after the first, second, and third monthly payments. Modify the
program so that it asks the user to enter the number of payments and then displays the
balance remaining after each of these payment.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    
    printf("Enter amount of loan: ");
    float loan;
    scanf("%f", &loan);
    printf("Enter interest rate: ");
    float interest_rate;
    scanf("%f", &interest_rate);
    printf("Enter monthly payment: ");
    float monthly_payment;
    scanf("%f", &monthly_payment);
    int number_of_payments;
    printf("Enter the number of payments: ");
    scanf("%d", &number_of_payments);

    float monthly_interest_rate = interest_rate / 100 / 12;
    for (int i = 0; i < number_of_payments; ++i)
    {
        loan = loan - monthly_payment + (loan * monthly_interest_rate);
        printf("Balance remaining after %d payments: $%.2f\n", i + 1, loan);
    } 

    return EXIT_SUCCESS;
}