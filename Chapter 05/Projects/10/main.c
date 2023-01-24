/*
Using the switch statement, write a program that converts a numerical grade into a letter
grade:

Enter numerical grade: 84
Letter grade: B

Use the following grading scale: A = 90 - 100, B = 80 - 89, C = 70 - 79, D = 60 - 69, F = 0 - 59.
Print an error message if the grade is larger than 100 or less than 0. Hint: Break the grade
into two digits, then use a switch statement to test the ten's digit.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    printf("Enter numerical grade: ");    
    int numerical_grade;
    scanf("%d", &numerical_grade);
    if (numerical_grade < 0 || numerical_grade > 100)
    {
        printf("Numerical grade %d is out of range (0 - 100 (inclusive)).", numerical_grade);
        return EXIT_FAILURE;
    }

    printf("Letter grade: ");
    switch (numerical_grade / 10)
    {
        case 10: // fallthrough
        case 9: 
            printf("A\n");
            break;
        case 8:
            printf("B\n");
            break;
        case 7:
            printf("C\n");
            break;
        case 6:
            printf("D\n");
            break;
        case 5: // fallthrough
        case 4: // fallthrough
        case 3: // fallthrough
        case 2: // fallthrough
        case 1: // fallthrough
        case 0:
            printf("F\n");
            break;
        default:
            printf("Unhandled switch %d", numerical_grade);
            return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}