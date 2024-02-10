/*
Modify the inventory2.c program of Section 17.5 by adding an e (erase) command
that allows the user to remove a part from the database.
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
    struct part *next;
};

struct part *inventory = NULL; // points to first part

struct part *find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);
void erase(void);

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
            case 'e':
            {
                erase();
                break;
            }
            case 'q':
            {
                exit(EXIT_SUCCESS);
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
///        array. Returns a pointer to the node 
///        containing the part number; if the part
///        number is not found, returns NULL.
/// @param  
struct part *find_part(int number)
{
    struct part *p;

    for (p = inventory; p != NULL && number > p->number; p = p->next)
    {
        ;
    }

    if (p != NULL && number == p->number)
    {
        return p;
    }
    else
    {
        return NULL;
    }
}

/// @brief Prompts the user for information about a new
///        part and then inserts the part into the
///        inventory list; the list remains sorted by
///        part number. Prints an error message and
///        returns prematurely if the part already exists
///        or space could not be allocated for the part.
/// @param  
void insert(void)
{
    struct part *cur;
    struct part *prev;
    struct part *new_node;

    new_node = malloc(sizeof(struct part));
    if (new_node == NULL)
    {
        printf("Database is full; can't add more parts.\n");
        return;
    }

    printf("Enter part number: ");
    scanf("%d", &new_node->number);

    for (cur = inventory, prev = NULL; cur != NULL && new_node->number > cur->number; prev = cur, cur = cur->next)
    {
        ;
    }

    if (cur != NULL && new_node->number == cur->number)
    {
        printf("Part already exists.\n");
        free (new_node);
        return;
    }

    printf("Enter part name: ");
    read_line(new_node->name, NAME_LEN);
    printf("Enter quantity on hand: ");
    scanf("%d", &new_node->on_hand);

    new_node->next = cur;

    if (prev == NULL)
    {
        inventory = new_node;
    }
    else
    {
        prev->next = new_node;
    }
}

/// @brief Prompts the user to enter a part number, then
///        looks up the part in the database. If the part
///        exists, prints the name and quantity on hand;
///        if not, prints an error message.
/// @param  
void search(void)
{
    int number;
    struct part *p;

    printf("Enter part number: ");
    scanf("%d", &number);
    p=find_part(number);

    if (p != NULL)
    {
        printf("Part name: %s\n", p->name);
        printf("Quantity on hand: %d\n", p->on_hand);
    }
    else
    {
        printf("Part not found.\n");
    }
}

/// @brief Prompts the user to enter a part number.
///        Prints an error message if the part doesn't
///        exist; otherwise, prompts the user to enter
///        change in quantity on hand and updates the
///        database.
/// @param  
void update(void)
{
    int number, change;
    struct part *p;

    printf("Enter a part number: ");
    scanf("%d", &number);
    p = find_part(number);

    if (p != NULL)
    {
        printf("Enter change in quantity on hand:  ");
        scanf("%d", &change);
        p->on_hand += change;
    }
    else
    {
        printf("Part not found.\n");
    }
}

/// @brief Prints a listing of all parts in the database,
///        showing the part number, part name, and
///        quantity on hand. Part numbers will appear in
///        ascending order.
/// @param  
void print(void)
{
    printf("Part Number     Part Name               "
           "Quantity on Hand\n");

    for (struct part *p = inventory; p != NULL; p = p->next)
    {
        printf("%7d     %-25s%11d\n", p->number, p->name, p->on_hand);
    }
}

/// @brief Asks the user to input a part number
///        to be erased from the database.
/// @param number of the part to erase.
void erase(void)
{
    int number;
    struct part *p;
    struct part *cur;
    struct part *prev;

    printf("Enter number of part to be erased: ");
    scanf("%d", &number);
    p = find_part(number);

    if (p == NULL)
    {
        printf("Couldn't find part number: %d\n", number);
        return;
    }

    if (p == inventory)
    {
        inventory = p->next;
        free(p);
        return;
    }

    for(cur = inventory; cur != NULL && cur != p; prev = cur, cur = cur->next)
    {
        ;
    }

    prev->next = cur->next;
    free(p);
}