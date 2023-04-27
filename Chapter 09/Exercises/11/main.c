/*
Write the following function:

float compute_GPA(char grades[], int n);

The grades array will contain letter grades (A, B, C, D or F, either upper-case or lower-
case); n is the length of the array. The function should return the average of the grades
(assume that A = 4, B = 3, C = 2, D = 1 and F = 0).
*/

#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

#define LENGTH 5

float compute_GPA(char grades[], int n);

int main(void)
{
    char grades[LENGTH] = {'A', 'B', 'C', 'D', 'F'} ;
    
    printf("GPA: %.1f\n", compute_GPA(grades, LENGTH));

    exit(EXIT_SUCCESS);
}

float compute_GPA(char grades[], int n)
{
    float total = 0.0f;

    for (int i = 0; i < n; i++)
    {
        switch(toupper(grades[i]))
        {
            case 'A':
            {
                total += 4;
                break;
            }
            case 'B':
            {
                total += 3;
                break;
            }
            case 'C':
            {
                total +=2;
                break;
            }
            case 'D':
            {
                total +=1;
                break;
            }
            case 'F':
            {
                break;
            }
            default:
            {
                printf("Error %c is not a valid grade. Valid grades = A, B, C, D, F.\n", grades[i]);
                exit(EXIT_FAILURE);
            }
        }
    }

    return total / n;
}