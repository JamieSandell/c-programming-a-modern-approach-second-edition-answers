/*
Modify the justify program of Section 15.3 so that it reads from one text file and writes
to another. Have the program obtain the names of both files from the command line.
*/

/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King                                         *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.                                  *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.      *
 *********************************************************/

/* justify.c (Chapter 15, page 363) */
/* Formats a file of text */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "line.h"
#include "word.h"

#define MAX_MESSAGE_LENGTH 512
#define MAX_WORD_LEN 20

void terminate(bool condition, const char *message);

int main(int argc, char *argv[])
{
  char message[MAX_MESSAGE_LENGTH];
  snprintf(message, MAX_MESSAGE_LENGTH, "Error: Incorrect usage. Expected usage: justify input.txt output.txt\n");
  terminate(argc != 3, message);

  char word[MAX_WORD_LEN+2];
  int word_len;
  
  FILE *fpr = fopen(argv[1], "r");
  snprintf(message, MAX_MESSAGE_LENGTH, "Error: failed to open %s for reading.\n", argv[1]);
  terminate(fpr == NULL, message);

  FILE *fpw = fopen(argv[2], "w");
  snprintf(message, MAX_MESSAGE_LENGTH, "Error: failed to open %s for writing.\n", argv[2]);
  terminate(fpw == NULL, message);

  clear_line();
  for (;;) {
    read_word(word, MAX_WORD_LEN+1);
    word_len = strlen(word);
    if (word_len == 0) {
      flush_line();
      return 0;
    }
    if (word_len > MAX_WORD_LEN)
      word[MAX_WORD_LEN] = '*';
    if (word_len + 1 > space_remaining()) {
      write_line();
      clear_line();
    }
    add_word(word);
  }

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