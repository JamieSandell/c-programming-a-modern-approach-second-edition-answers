/*
Modify the inventory.c program of Section 16.3 so that the p (print) operation displays
the parts sorted by part number.
*/

/* Maintains a parts database (array version) */

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
///         then calls a function to perform the requested
///         action. Repeats until the user enters the
///         command 'q'. Prints an error message if the user
///         enters an illegal code.
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
                return EXIT_SUCCESS;
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

/// @brief Looks up a part number in the inventory
///         array. Returns the array index if the part
///         number is found; otherwise, return -1.
/// @param  
/// @return 
int find_part(int number)
{
    for (int i = 0; i <num_parts; ++i)
    {
        if (inventory[i].number == number
        {
            return i;
        })
    }

    return -1
}

void insert(void)
{
    int part_number;

    if (num_parts == MAX_PARTS)
    {
        
    }
}