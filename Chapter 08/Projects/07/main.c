/*
Write a program that reads a 5 x 5 array of integers and then prints the row sums and the
column sums:

Enter row 1: 8 3 9 0 10
Enter row 2: 3 5 17 1 1
Enter row 3: 2 8 6 23 1
Enter row 4: 15 7 3 2 9
Enter row 5: 6 14 2 6 0

Row totals: 30 27 40 36 28
Column totals: 34 37 37 32 21
*/

#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    int numbers[5][5] = {0};
    int row_totals[5] = {0};
    int column_totals[5] = {0};

    for (int i = 0; i < 5; i++)
    {
        printf("Enter row %d: ", i + 1);
        scanf("%d %d %d %d %d", &numbers[i][0], &numbers[i][1], &numbers[i][2], &numbers[i][3], &numbers[i][4]);
    }

    printf("Row totals: ");
    for (int row = 0; row < 5; row++)
    {
        for (int column = 0; column < 5; column++)
        {
            row_totals[row] += numbers[row][column];
        }
        printf("%d ", row_totals[row]);
    }
    printf("\n");

    printf("Column totals: ");
    for (int column = 0; column < 5; column++)
    {
        for (int row = 0; row < 5; row++)
        {
            column_totals[column] += numbers[row][column];
        }
        printf("%d ", column_totals[column]);
    }
    printf("\n");

    return EXIT_SUCCESS;
}