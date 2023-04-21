/*
Modify Programming Project 7 so that it prompts for five quiz grades for each of five stu-
dents, then computes the total score and average score for each student, and the average
score, high score, and low score for each quiz.
*/

#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    int numbers[5][5] = {0};
    int row_totals[5] = {0};
    int column_totals[5] = {0};
    int high_score = 0;
    int low_score = 100;
    int quiz_score;
    int student_total;
    int student;
    int quiz;
    int quiz_total;

    printf("Enter five quiz grades for each of the five students\n");
    for (int i = 0; i < 5; i++)
    {
        printf("Quiz %d: ", i + 1);
        scanf("%d %d %d %d %d", &numbers[i][0], &numbers[i][1], &numbers[i][2], &numbers[i][3], &numbers[i][4]);
    }

    printf("Quiz Scores:\n"); // Row[0] = Quiz 1...Row[n] = Quiz n+1
    for (int row = 0; row < 5; row++)
    {
        for (int column = 0; column < 5; column++)
        {
            quiz_score = numbers[row][column];
            row_totals[row] += quiz_score;
            if (quiz_score > high_score)
            {
                high_score = quiz_score;
            }
            else if (quiz_score < low_score)
            {
                low_score = quiz_score;
            }
        }
        quiz = row + 1;
        quiz_total = row_totals[row];
        printf("Quiz %d average: %d\n", quiz, quiz_total / 5);
        printf("Quiz %d high: %d\n", quiz, high_score);
        printf("Quiz %d low: %d\n", quiz, low_score);
        high_score = 0;
        low_score = 100;
    }
    printf("\n");

    printf("Student Scores:\n"); // Column[0] = Student 1..Column[n] = Student n+1
    for (int column = 0; column < 5; column++)
    {
        for (int row = 0; row < 5; row++)
        {
            column_totals[column] += numbers[row][column];
        }
        student_total = column_totals[column];
        student = column + 1;
        printf("Student %d total: %d\n", student, student_total);
        printf("Student %d average: %d\n", student, student_total / 5);
    }
    printf("\n");

    return EXIT_SUCCESS;
}