/*
Write a program that reads a series of phone numbers from a file and displays them in a
standard format. Each line of the file will contain a single phone number, but the numbers
may be in a variety of formats. You may assume that each line contains 10 digits, possibly
mixed with other characters (which should be ignored). For example, suppose that the file
contains the following lines:

404.817.6900
(215) 686-1776
312-746-6000
877 275 5273
6173434200
The output of the program should have the following appearance:

(404) 817-6900
(215) 686-1776
(312) 746-6000
(877) 275-5273
(617) 343-4200
Have the program obtain the file name from the command line.
*/

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 256
#define MAX_MESSAGE_SIZE 512
#define MAX_DIGITS_PER_LINE 10

void terminate(bool condition, const char *message);

int main(int argc, char *argv[])
{
    char message[MAX_MESSAGE_SIZE];
    snprintf(message, MAX_MESSAGE_SIZE, "Incorrect program usage. Example usage: main phone_numbers.txt\n");
    terminate(argc != 2, message);

    FILE *fpr = fopen(argv[1], "r");
    snprintf(message, MAX_MESSAGE_SIZE, "Error opening %s\n", argv[1]);
    terminate(fpr == NULL, message);

    char buffer[BUFFER_SIZE];
    int digit_count = 0;

    while (fgets(buffer, BUFFER_SIZE, fpr) != NULL)
    {
        for (size_t i = 0; i < BUFFER_SIZE && buffer[i] != '\0'; ++i)
        {
            if (isdigit(buffer[i]))
            {
                ++digit_count;

                switch (digit_count)
                {
                    case 1:
                    {
                        printf("(%c", buffer[i]);
                        break;
                    }
                    case 3:
                    {
                        printf("%c)", buffer[i]);
                        break;
                    }
                    case 4:
                    {
                        printf(" %c", buffer[i]);
                        break;
                    }
                    case 7:
                    {
                        printf("-%c", buffer[i]);
                        break;
                    }
                    case 10:
                    {
                        printf("%c\n", buffer[i]);
                        break;
                    } 
                    default:
                    {
                        putchar(buffer[i]);
                    }
                }
            }
        }

        digit_count = 0;  
    }
    
    snprintf(message, MAX_MESSAGE_SIZE, "Error closing %s\n", argv[1]);
    terminate(fclose(fpr) == EOF, message);

    return EXIT_SUCCESS;
}

void terminate(bool condition, const char *message)
{
    if (condition)
    {
        fprintf(stderr, "%s", message);
        exit(EXIT_FAILURE);
    }
}