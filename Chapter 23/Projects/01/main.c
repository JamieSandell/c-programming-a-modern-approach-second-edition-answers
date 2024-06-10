/*
Write a program that finds the roots of the equation ax2 + bx + c = 0 using the formula

x = -b +- sqrt(bsquared - 4ac) / 2a

Have the program prompt for the values of a, b and c, then print both values of x (If b2
- 4ac is negative, the program should instead print a message to the effect that the roots are
complex). 
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    double a, b, c, radical, root1, root2;

    printf("For ax^2 + bx + c = 0, enter a: ");
    scanf("%lf", &a);
    printf("Enter b: ");
    scanf("%lf", &b);
    printf("Enter c: ");
    scanf("%lf", &c);

    radical = b * b - (4 * a * c);
    if (radical < 0)
    {
        printf("The roots to the given quadratic are complex.\n");
    }
    else
    {
        radical = sqrt(radical);
        root1 = (-b + radical) / (2 * a);
        root2 = (-b - radical) / (2 * a);
        if (root1 == root2)
        {
            printf("1 root: x = %lf\n", root1);
        }
        else
        {
            printf("2 roots: x = %lf or %lf\n", root1, root2);
        }
    }

    return EXIT_SUCCESS;
}