/*
Modify the inventory.c program of Section 16.3 by adding two new operations:

Save the database in a specified file.
Load the database from a specified file.

Use the codes d (dump) and r (restore), respectively, to represent these operations. The
interaction with the user should have the following appearance:

Enter operation code: d
Enter name of output file: inventory.dat

Enter operation code: r
Enter name of input file: inventory.dat

Hint: Use fwrite to write the array containing the parts to a binary file. Use fread to
restore the array by reading it from a file.
*/

/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King                                         *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.                                  *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.      *
 *********************************************************/

/* inventory.c (Chapter 16, page 391) */
/* Maintains a parts database (array version) */

#include <stdio.h>
#include "readline.h"

#define NAME_LEN 25
#define MAX_PARTS 100
#define MAX_FILENAME_LEN 255

struct part {
  int number;
  char name[NAME_LEN+1];
  int on_hand;
} inventory[MAX_PARTS];

int num_parts = 0;   /* number of parts currently stored */

int find_part(int number);
void dump(void);
void insert(void);
void restore(void);
void search(void);
void update(void);
void print(void);

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
 * find_part: Looks up a part number in the inventory     *
 *            array. Returns the array index if the part  *
 *            number is found; otherwise, returns -1.     *
 **********************************************************/
int find_part(int number)
{
  int i;

  for (i = 0; i < num_parts; i++)
    if (inventory[i].number == number)
      return i;
  return -1;
}

/**********************************************************
 * dump:  Save the database in a specified file.          *
 **********************************************************/
void dump(void)
{
  char filename[MAX_FILENAME_LEN];
  printf("Enter name of output file: ");
  int result = read_line(filename, MAX_FILENAME_LEN);

  if (result == 0)
  {
    fprintf(stderr, "Error: no filename entered to dump to.\n");
  }

  FILE *fpw = fopen(filename, "wb");
  
  if (fpw == NULL)
  {
    fprintf(stderr, "Error opening %s for writing.\n", filename);
    return;
  }

  if (fwrite(inventory, sizeof(struct part), num_parts, fpw) != (size_t)num_parts)
  {
    if (ferror(fpw))
    {
      fprintf(stderr, "Error writing to %s\n", filename);
      return;
    }
  }

  if (fclose(fpw) == EOF)
  {
    fprintf(stderr, "Error closing %s after writing.\n", filename);
  }
}

/**********************************************************
 * insert: Prompts the user for information about a new   *
 *         part and then inserts the part into the        *
 *         database. Prints an error message and returns  *
 *         prematurely if the part already exists or the  *
 *         database is full.                              *
 **********************************************************/
void insert(void)
{
  int part_number;

  if (num_parts == MAX_PARTS) {
    printf("Database is full; can't add more parts.\n");
    return;
  }

  printf("Enter part number: ");
  scanf("%d", &part_number);
  if (find_part(part_number) >= 0) {
    printf("Part already exists.\n");
    return;
  }

  inventory[num_parts].number = part_number;
  printf("Enter part name: ");
  read_line(inventory[num_parts].name, NAME_LEN);
  printf("Enter quantity on hand: ");
  scanf("%d", &inventory[num_parts].on_hand);
  num_parts++;
}

/**********************************************************
 * restore: Restore the database from a specified file.   *
 **********************************************************/
void restore(void)
{
  char filename[MAX_FILENAME_LEN];
  printf("Enter name of input file: ");
  int result = read_line(filename, MAX_FILENAME_LEN);

  if (result == 0)
  {
    fprintf(stderr, "Error: no filename entered.\n");
    return;
  }

  FILE *fpr = fopen(filename, "rb");

  if (fpr == NULL)
  {
    printf("Error opening %s for reading.\n", filename);
    return;
  }

  size_t number_of_parts_read = fread(inventory, sizeof(struct part), MAX_PARTS, fpr);

  if (number_of_parts_read != MAX_PARTS)
  {
    if (ferror(fpr))
    {
      fprintf(stderr, "Error whilst reading from %s\n", filename);
      return;
    }
  }

  if (fclose(fpr) == EOF)
  {
    fprintf(stderr, "Error closing %s after reading.\n", filename);
  }

  num_parts = number_of_parts_read;
}

/**********************************************************
 * search: Prompts the user to enter a part number, then  *
 *         looks up the part in the database. If the part *
 *         exists, prints the name and quantity on hand;  *
 *         if not, prints an error message.               *
 **********************************************************/
void search(void)
{
  int i, number;

  printf("Enter part number: ");
  scanf("%d", &number);
  i = find_part(number);
  if (i >= 0) {
    printf("Part name: %s\n", inventory[i].name);
    printf("Quantity on hand: %d\n", inventory[i].on_hand);
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
  int i, number, change;

  printf("Enter part number: ");
  scanf("%d", &number);
  i = find_part(number);
  if (i >= 0) {
    printf("Enter change in quantity on hand: ");
    scanf("%d", &change);
    inventory[i].on_hand += change;
  } else
    printf("Part not found.\n");
}

/**********************************************************
 * print: Prints a listing of all parts in the database,  *
 *        showing the part number, part name, and         *
 *        quantity on hand. Parts are printed in the      *
 *        order in which they were entered into the       *
 *        database.                                       *
 **********************************************************/
void print(void)
{
  int i;

  printf("Part Number   Part Name                  "
         "Quantity on Hand\n");
  for (i = 0; i < num_parts; i++)
    printf("%7d       %-25s%11d\n", inventory[i].number,
           inventory[i].name, inventory[i].on_hand);
}
