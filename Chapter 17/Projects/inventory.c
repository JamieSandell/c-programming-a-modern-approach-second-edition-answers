/*
Modify the inventory.c program of Section 16.3 so that the inventory array is allo-
cated dynamically and later reallocated when it fills up. Use malloc initially to allocate
enough space for 10 part structures. When the array has no more room for new
parts, use realloc to double its size. Repeat the doubling step each time the array
becomes full.
*/

#include <stdio.h>
#include <stdlib.h>
#include "readline.h"

#define NAME_LEN 25
#define MAX_PARTS 100

struct part
{
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
} inventory[MAX_PARTS];

int num_parts = 0; // number of parts currently stored

int find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);

/// @brief Prompts the user to enter an operation code,
///        then calls a function to perform the requested
///        action. Repeats until the user enters the
///        command 'q'. Prints an error message if the user
///        enters an illegal code.
/// @param  
/// @return 
int main(void)
{
    char code;

    for (;;)
    {
        printf("Enter operation code: ");
        scanf(" %c", &code);
        while (getchar() != '\n') // skips to end of line
        {
            ;
        }

        switch (code)
        {
            case 'i':
            {
                insert();
                break;
            }
            case 's':
            {
                search();
                break;
            }
            case 'u':
            {
                update();
                break;
            }
            case 'p':
            {
                print();
                break;
            }
            case 'q':
            {
                print();
                break;
            }
            default:
            {
                printf("Illegal code\n");
                break;
            }
        }

        printf("\n");
    }

    return EXIT_SUCCESS;
}