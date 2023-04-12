/*
Write a program that evaluates an expression:

Enter an expression: 1+2.5*3
Value of expression: 10.5

The operands in the expression are floating-point numbers; the operators are +, -, * and /.
The expression is evalued from left to right (no operator taes precedence over any other
operator).
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    double num = 0.0, total = 0.0;
    char c;

    printf("Enter an expression: ");
    scanf("%lf", &total);

    while ((c = getchar()) != '\n')
    {
        switch (c)
        {
            case '+':
            {
                scanf("%lf", &num);
                total += num;
                break;
            }
            case '-':
            {
                scanf("%lf", &num);
                total -= num;
                break;
            }
            case '*':
            {
                scanf("%lf", &num);
                total *= num;
                break;
            }
            case '/':
            {
                scanf("%lf", &num);
                total /= num;
                break;
            }
            default:
            {
                break;
            }
        }
    }

    printf("Value of expression: %f\n", total);  

    return EXIT_SUCCESS;
}