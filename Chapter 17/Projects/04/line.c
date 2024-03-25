/*
Modify the justify program of Section 15.3 by rewriting the line.c file so that it
stores the current line in a linked list. Each node in the list will store a single word. The
line array will be replaced with a variable that points to the node containing the first word.
This variable will store a null pointer whenever the line is empty.
*/

/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King                                         *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.                                  *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.      *
 *********************************************************/

/* line.c (Chapter 15, page 364) */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "line.h"
#include "storage.h"

#define MAX_LINE_LEN 60

struct node
{
  char *word;
  struct node *next;
};

struct node *line = NULL;
int line_len = 0;
int num_words = 0;

void clear_line(void)
{
  struct node *temp;

  while (line)
  {
    temp = line;
    line = line->next;
    free(temp->word);
    free(temp);
  }

  line_len = 0;
  num_words = 0;
}

void add_word(const char *word)
{
  struct node *new_node;
  size_t word_length = strlen(word);
  int word_mem = word_length + 1;

  new_node = my_malloc(sizeof(*new_node));
  new_node->word = my_malloc(word_mem);
  strcpy_s(new_node->word, word_mem, word);
  line->next = my_malloc(sizeof(*(line->next)));
  line = line->next;
  line_len += word_mem;
  num_words++;
}

int space_remaining(void)
{
  return MAX_LINE_LEN - line_len;
}

void write_line(void)
{
  int extra_spaces, spaces_to_insert, j;
  struct node *cur = first_word;
  int char_count = 0;

  extra_spaces = MAX_LINE_LEN - line_len;

  while (char_count < line_len && cur != NULL)
  {
    printf("%s", cur->word);

    if (num_words > 1)
    {
      spaces_to_insert = extra_spaces / (num_words - 1);

      for (j = 1; j <= spaces_to_insert + 1; j++)
      {
        putchar(' ');
      }        

      extra_spaces -= spaces_to_insert;
      num_words--;
    }   

    cur = cur->next;
  }

  putchar('\n');
}

void flush_line(void)
{
  struct node *temp = first_word;

  while (temp != NULL)
  {
    printf("%s ", temp->word);
    temp = temp->next;
  }
}