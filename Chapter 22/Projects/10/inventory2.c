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
#include <string.h>
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
void insert_with_params(int number, int on_hand, const char *name);
void read_bytes(void *buffer, size_t element_size, size_t element_count, FILE *stream, const char *filename);
void restore(void);
void search(void);
void update(void);
void print(void);
void terminate(bool condition, const char *message);
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
      case 'd': dump();
                break;
      case 'i': insert();
                break;
      case 'r': restore();
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
    write_bytes(p->name, 1, NAME_LEN + 1, fpw, filename);
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
  int number;
  int on_hand;
  char name[NAME_LEN + 1];

  printf("Enter part number: ");
  scanf("%d", &number);
  printf("Enter part name: ");
  read_line(name, NAME_LEN);
  printf("Enter quantity on hand: ");
  scanf("%d", &on_hand);
  insert_with_params(number, on_hand, name);
}

/// @brief Adds a part to the inventory without user input.
/// @param number 
/// @param on_hand 
/// @param name 
void insert_with_params(int number, int on_hand, const char *name)
{
  struct part *cur, *prev, *new_node;

  new_node = malloc(sizeof(struct part));
  if (new_node == NULL) {
    printf("Database is full; can't add more parts.\n");
    return;
  }

  new_node->number = number;

  for (cur = inventory, prev = NULL;
       cur != NULL && new_node->number > cur->number;
       prev = cur, cur = cur->next)
    ;
  if (cur != NULL && new_node->number == cur->number) {
    printf("Part already exists.\n");
    free(new_node);
    return;
  }

  strncpy(new_node->name, name, NAME_LEN + 1);
  new_node->on_hand = on_hand;

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

/**********************************************************
 * restore: Clears the inventory and then restores the
 *          inventory from a a binary file.               *
 **********************************************************/
void restore(void)
{
  printf("Enter a file to restore from, e.g. inventory.dat ");
  char filename[MAX_FILENAME_LENGTH];

  if (read_line(filename, MAX_FILENAME_LENGTH) < 1)
  {
    fprintf(stderr, "Error: Filename must be at least 1 character long.\n");
    return;
  }

  FILE *fpr = fopen(filename, "rb");

  if (fpr == NULL)
  {
    fprintf(stderr, "Error opening %s for reading.\n", filename);
    return;
  }

  if (inventory != NULL)
  {
    struct part *current = inventory;
    struct part *next;

    while (current != NULL)
    {
      next = current->next;
      free(current);
      current = next;
    }

    inventory = NULL;
  }

  char name[NAME_LEN + 1];
  int number;
  int on_hand;
  int c;

  while ((c = fgetc(fpr)) != EOF)
  {
    if (ungetc(c, fpr) == EOF)
    {
      fprintf(stderr, "Error putting character back on stream whilst reading %s\n", filename);
      return;
    }

    read_bytes(name, 1, NAME_LEN + 1, fpr, filename);
    read_bytes(&number, sizeof(int), 1, fpr, filename);
    read_bytes(&on_hand, sizeof(int), 1, fpr, filename);
    insert_with_params(number, on_hand, name);
  }

  if (ferror(fpr))
  {
    fprintf(stderr, "Error whilst reading %s", filename);
    return;
  }

  if (fclose(fpr) == EOF)
  {
    fprintf(stderr, "Error closing %s\n", filename);
  }
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

/// @brief Wrapper for fread that prints an error if on occurred and terminates.
/// @param buffer Bytes to read to.
/// @param element_size 
/// @param element_count 
/// @param stream Input stream.
/// @param filename Name of file attempting to read from.
void read_bytes(void *buffer, size_t element_size, size_t element_count, FILE *stream, const char *filename)
{
  snprintf(message, MAX_MESSAGE_LENGTH, "Failed to read from %s\n", filename);
  terminate(fread(buffer, element_size, element_count, stream) != element_count, message);
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