/*
Modify the inventory2.c program of Section 17.5 by adding the d (dump) and r
(restore) operations described in Programming Project 8. Since the part structures aren't
stored in an array, the d operation can't save them all by a single call of fwrite. Instead, it
will need to visit each node in the linked list, writing the part number, part name and quan-
tity on hand to a file (Don't save the next pointer; it won't be valid once the program ter-
minates). As it reads parts from a file, the r operation will rebuild the list one node at a time.
*/

/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King                                         *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.                                  *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.      *
 *********************************************************/

/* inventory2.c (Chapter 17, page 434) */
/* Maintains a parts database (linked list version) */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "readline.h"

#define MAX_FILENAME_LENGTH 255
#define MAX_MESSAGE_LENGTH 512
#define NAME_LEN 25

struct part {
  int number;
  char name[NAME_LEN+1];
  int on_hand;
  struct part *next;
};

struct part *inventory = NULL;   /* points to first part */

char message[MAX_MESSAGE_LENGTH];

void dump(void);
struct part *find_part(int number);
void insert(void);
void restore(void);
void search(void);
void update(void);
void print(void);
void terminate(const char *message);
void write_bytes(const void *buffer, size_t element_size, size_t element_count, FILE *stream, const char *filename);

/**********************************************************
 * main: Prompts the user to enter an operation code,     *
 *       then calls a function to perform the requested   *
 *       action. Repeats until the user enters the        *
 *       command 'q'. Prints an error message if the user *
 *       enters an illegal code.                          *
 **********************************************************/
int main(void)
{
  char code;

  for (;;) {
    printf("Enter operation code: ");
    scanf(" %c", &code);
    while (getchar() != '\n')   /* skips to end of line */
      ;
    switch (code) {
      case 'i': insert();
                break;
      case 's': search();
                break;
      case 'u': update();
                break;
      case 'p': print();
                break;
      case 'q': return 0;
      default:  printf("Illegal code\n");
    }
    printf("\n");
  }
}

/**********************************************************
 * dump: Saves the inventory to a binary file.            *
 **********************************************************/
void dump(void)
{
  printf("Please enter the file to dump the inventory to, e.g. inventory.dat: ");
  char filename[MAX_FILENAME_LENGTH];

  if (read_line(filename, MAX_FILENAME_LENGTH) < 1)
  {
    fprintf(stderr, "Error: Filename must be at least 1 character long.\n");
    return;
  }

  FILE *fpw = fopen(filename, "wb");

  if (fpw == NULL)
  {
    fprintf(stderr, "Error: Failed to open %s for dumping.\n", filename);
    return;
  }

  struct part *p = inventory;

  while (p != NULL)
  {
    write_bytes(p->name, 1, strlen(p->name), fpw, filename);
    write_bytes(&(p->number), sizeof(int), 1, fpw, filename);
    write_bytes(&(p->on_hand), sizeof(int), 1, fpw, filename);
    p = p->next;
  }

  if (fclose(fpw) == EOF)
  {
    fprintf(stderr, "Error: failed to close %s after writing.\n", filename);
  }
}

/**********************************************************
 * find_part: Looks up a part number in the inventory     *
 *            list. Returns a pointer to the node         *
 *            containing the part number; if the part     *
 *            number is not found, returns NULL.          *
 **********************************************************/
struct part *find_part(int number)
{
  struct part *p;

  for (p = inventory;
       p != NULL && number > p->number;
       p = p->next)
    ;
  if (p != NULL && number == p->number)
    return p;
  return NULL;
}

/**********************************************************
 * insert: Prompts the user for information about a new   *
 *         part and then inserts the part into the        *
 *         inventory list; the list remains sorted by     *
 *         part number. Prints an error message and       *
 *         returns prematurely if the part already exists *
 *         or space could not be allocated for the part.  *
 **********************************************************/
void insert(void)
{
  struct part *cur, *prev, *new_node;

  new_node = malloc(sizeof(struct part));
  if (new_node == NULL) {
    printf("Database is full; can't add more parts.\n");
    return;
  }

  printf("Enter part number: ");
  scanf("%d", &new_node->number);

  for (cur = inventory, prev = NULL;
       cur != NULL && new_node->number > cur->number;
       prev = cur, cur = cur->next)
    ;
  if (cur != NULL && new_node->number == cur->number) {
    printf("Part already exists.\n");
    free(new_node);
    return;
  }

  printf("Enter part name: ");
  read_line(new_node->name, NAME_LEN);
  printf("Enter quantity on hand: ");
  scanf("%d", &new_node->on_hand);

  new_node->next = cur;
  if (prev == NULL)
    inventory = new_node;
  else
    prev->next = new_node;
}

/**********************************************************
 * search: Prompts the user to enter a part number, then  *
 *         looks up the part in the database. If the part *
 *         exists, prints the name and quantity on hand;  *
 *         if not, prints an error message.               *
 **********************************************************/
void search(void)
{
  int number;
  struct part *p;

  printf("Enter part number: ");
  scanf("%d", &number);
  p = find_part(number);
  if (p != NULL) {
    printf("Part name: %s\n", p->name);
    printf("Quantity on hand: %d\n", p->on_hand);
  } else
    printf("Part not found.\n");
}

/**********************************************************
 * update: Prompts the user to enter a part number.       *
 *         Prints an error message if the part doesn't    *
 *         exist; otherwise, prompts the user to enter    *
 *         change in quantity on hand and updates the     *
 *         database.                                      *
 **********************************************************/
void update(void)
{
  int number, change;
  struct part *p;

  printf("Enter part number: ");
  scanf("%d", &number);
  p = find_part(number);
  if (p != NULL) {
    printf("Enter change in quantity on hand: ");
    scanf("%d", &change);
    p->on_hand += change;
  } else
    printf("Part not found.\n");
}

/**********************************************************
 * print: Prints a listing of all parts in the database,  *
 *        showing the part number, part name, and         *
 *        quantity on hand. Part numbers will appear in   *
 *        ascending order.                                *
 **********************************************************/
void print(void)
{
  struct part *p;

  printf("Part Number   Part Name                  "
         "Quantity on Hand\n");
  for (p = inventory; p != NULL; p = p->next)
    printf("%7d       %-25s%11d\n", p->number, p->name,
           p->on_hand);
}

/// @brief If the condition is true, prints message and terminates.
/// @param condition 
/// @param message 
void terminate(bool condition, const char *message)
{
  if (condition)
  {
    fprintf(stderr, "%s", message);
    exit(EXIT_FAILURE);
  }
}

/// @brief Wrapper for fwrite that prints an error if one occurred and terminates.
/// @param buffer bytes to write
/// @param element_size 
/// @param element_count 
/// @param stream output stream
/// @param filename name of file attempting to write to.
void write_bytes(const void *buffer, size_t element_size, size_t element_count, FILE *stream, const char *filename)
{
  snprintf(message, MAX_MESSAGE_LENGTH, "Failed to write to %s\n", filename);
  terminate(fwrite(buffer, element_size, element_count, stream) != element_count, message);
}