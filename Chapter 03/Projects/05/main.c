/*
Write a program that asks the user to enter the numbers from 1 to 16 (in any order) and then
displays the numbers in a 4 x 4 arrangement, followed by the sums of the rows, columns,
and diagnols:
Enter the numbers from 1 to 16 in any order:
16 3 2 13 5 10 11 8 9 6 7 12 4 15 14 1

16  3   2   13
5   10  11  8
9   6   7   12
4   15  14  1

Row sums: 34 34 34 34
Column sums: 34 34 34 34
Diagonal sums: 34 34

If the row, column, and diagonal sums are all the same (as they are in this example), the
numbers are said to form a magic square. The magic square shown here appears in a 1514
engraving by artist and mathemetician
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    printf("Enter the numbers from 1 to 16 in any order:\n");
    
    int cell_1_1, cell_1_2, cell_1_3, cell_1_4, // cell_row_column
        cell_2_1, cell_2_2, cell_2_3, cell_2_4,
        cell_3_1, cell_3_2, cell_3_3, cell_3_4,
        cell_4_1, cell_4_2, cell_4_3, cell_4_4;
    scanf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
            &cell_1_1, &cell_1_2, &cell_1_3, &cell_1_4,
            &cell_2_1, &cell_2_2, &cell_2_3, &cell_2_4,
            &cell_3_1, &cell_3_2, &cell_3_3, &cell_3_4,
            &cell_4_1, &cell_4_2, &cell_4_3, &cell_4_4);

    printf("%2d %2d %2d %2d\n", cell_1_1, cell_1_2, cell_1_3, cell_1_4);
    printf("%2d %2d %2d %2d\n", cell_2_1, cell_2_2, cell_2_3, cell_2_4);
    printf("%2d %2d %2d %2d\n", cell_3_1, cell_3_2, cell_3_3, cell_3_4);
    printf("%2d %2d %2d %2d\n", cell_4_1, cell_4_2, cell_4_3, cell_4_4);

    int row1_sum = cell_1_1 + cell_1_2 + cell_1_3 + cell_1_4;   
    int row2_sum = cell_2_1 + cell_2_2 + cell_2_3 + cell_2_4;
    int row3_sum = cell_3_1 + cell_3_2 + cell_3_3 + cell_3_4;
    int row4_sum = cell_4_1 + cell_4_2 + cell_4_3 + cell_4_4;
    printf("\nRow sums: %d %d %d %d\n", row1_sum, row2_sum, row3_sum, row4_sum);

    int col1_sum = cell_1_1 + cell_2_1 + cell_3_1 + cell_4_1;
    int col2_sum = cell_1_2 + cell_2_2 + cell_3_2 + cell_4_2;
    int col3_sum = cell_1_3 + cell_2_3 + cell_3_3 + cell_4_3;
    int col4_sum = cell_1_4 + cell_2_4 + cell_3_4 + cell_4_4;
    printf("Column sums: %d %d %d %d\n", col1_sum, col2_sum, col3_sum, col4_sum);

    int top_left_bottom_right_diagonal = cell_1_1 + cell_2_2 + cell_3_3 + cell_4_4;
    int top_right_bottom_left_diagonal = cell_1_4 + cell_2_3 + cell_3_2 + cell_4_1;
    printf("Diagonal sums: %d %d\n", top_left_bottom_right_diagonal, top_right_bottom_left_diagonal);
    
    
    return EXIT_SUCCESS;
}