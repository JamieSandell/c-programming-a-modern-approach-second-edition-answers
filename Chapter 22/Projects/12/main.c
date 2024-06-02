/*
Modify Programming Project 2 from Chapter 3 so that the program reads a series of items
from a file and displays the data in columns. Each line of the file will have the following
form:

item,price,mm/dd/yyyy

For example, suppose that the file contains the following lines:

583,13.5,10/24/2005
3912,599.99,7/27/2008

The output of the program should have the following appearance:

Item            Unit            Purchase
                Price           Date
583             $  13.50        10/24/2005
3912            $ 599.99        07/27/2008

Have the program obtain the file name from the command line.
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_MESSAGE_LENGTH 512

void terminate(bool condition, const char *message);

int main(int argc, char *argv[])
{
    char message[MAX_MESSAGE_LENGTH];
    snprintf(message, MAX_MESSAGE_LENGTH, "Error: incorrect program usage. Expected usage: main items.dat\n");
    terminate(argc != 2, message);
    FILE *fpr = fopen(argv[1], "rb");

    if (fpr == NULL)
    {
        snprintf(message, MAX_MESSAGE_LENGTH, "Error opening %s for reading.\n", argv[1]);
        terminate(true, message);
    }

    snprintf(message, MAX_MESSAGE_LENGTH, "Error seeking to the end of %s\n", argv[1]);
    terminate(fseek(fpr, 0L, SEEK_END), message);
    long file_size = ftell(fpr);
    terminate(file_size == 1)

    int item, year, month, day;
    float price;

    printf("Enter item number: ");
    scanf("%d", &item);

    printf("Enter unit price: ");
    scanf("%f", &price);

    printf("Enter purchase date (mm/dd/yyyy): ");
    scanf("%d /%d /%d", &month, &day, &year);

    printf("Item\t\tUnit\t\tPurchase\n\t\tPrice\t\tDate\n");
    printf("%d\t\t$%8.2f\t%.2d/%.2d/%.4d\n", item, price, month, day, year);

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