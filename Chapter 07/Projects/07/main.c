/*
Modify Programming Project 6 from Chapter 3 so that the user may add, subtract, multiply
or divide two fractions (by entering either +, -, * or / between the fractions).
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int num1, denom1, num2, denom2, result_num, result_denom;
    char operator;

    printf("Enter two fractions separated by an operator (+, -, *, or /), e.g: 5/6 + 3/4:\t");
    scanf("%d/%d %c %d/%d", &num1, &denom1, &operator, &num2, &denom2);

    switch (operator)
    {
        case '+':
        {
            result_num = num1 * denom2 + num2 * denom1;
            result_denom = denom1 * denom2;
            break;
        }
        case '-':
        {
            result_num = num1 * denom2 - num2 * denom1;
            result_denom = denom1 * denom2;
            break;
        }
        case '*':
        {
            result_num = num1 * num2;
            result_denom = denom1 * denom2;
            break;
        }
        case '/':
        {
            result_num = num1 * denom2;
            result_denom = num2 * denom1;
            break;
        }
        default:
        {
            printf("Invalid operator!");
            return EXIT_FAILURE;
        }
    }    

    printf("The sum is %d/%d\n", result_num, result_denom);

    return EXIT_SUCCESS;
}