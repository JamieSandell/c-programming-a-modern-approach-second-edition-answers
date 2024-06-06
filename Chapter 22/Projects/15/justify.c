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

#define MAX_MESSAGE_LENGTH 512
#define MAX_LINE_LEN 60
#define MAX_WORD_LEN 20

FILE *fpr;
FILE *fpw;
char line[MAX_LINE_LEN+1];
int line_len = 0;
int num_words = 0;
char message[MAX_MESSAGE_LENGTH];

void clear_line(void);
void add_word(const char *word);
int space_remaining(void);
void write_line(void);
void flush_line(void);
int read_char(void);
void read_word(char *word, int len);
void terminate(bool condition, const char *message);

int main(int argc, char *argv[])
{
  snprintf(message, MAX_MESSAGE_LENGTH, "Error: Incorrect usage. Expected usage: justify input.txt output.txt\n");
  terminate(argc != 3, message);

  char word[MAX_WORD_LEN+2];
  int word_len;
  
  fpr = fopen(argv[1], "r");
  snprintf(message, MAX_MESSAGE_LENGTH, "Error: failed to open %s for reading.\n", argv[1]);
  terminate(fpr == NULL, message);

  fpw = fopen(argv[2], "w");
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

int read_char(void)
{
  int ch = fgetc(fpr);

  if (ch == '\n' || ch == '\t')
    return ' ';
  return ch;
}

void read_word(char *word, int len)
{
  int ch, pos = 0;

  while ((ch = read_char()) == ' ')
    ;
  while (ch != ' ' && ch != EOF) {
    if (pos < len)
      word[pos++] = ch;
    ch = read_char();
  }
  word[pos] = '\0';
}

void clear_line(void)
{
  line[0] = '\0';
  line_len = 0;
  num_words = 0;
}

void add_word(const char *word)
{
  if (num_words > 0) {
    line[line_len] = ' ';
    line[line_len+1] = '\0';
    line_len++;
  }
  strcat(line, word);
  line_len += strlen(word);
  num_words++;
}

int space_remaining(void)
{
  return MAX_LINE_LEN - line_len;
}

void write_line(void)
{
  int extra_spaces, spaces_to_insert, i, j;

  extra_spaces = MAX_LINE_LEN - line_len;
  snprintf(message, MAX_MESSAGE_LENGTH, "Error: Failed writing to file.\n");
  for (i = 0; i < line_len; i++) {
    if (line[i] != ' ')
    {
      terminate(fputc(line[i], fpw) == EOF, message);
    }
    else {
      spaces_to_insert = extra_spaces / (num_words - 1);
      for (j = 1; j <= spaces_to_insert + 1; j++)
        terminate(fputc(' ', fpw) == EOF, message);
      extra_spaces -= spaces_to_insert;
      num_words--;
    }
  }
  terminate(fputc('\n', fpw) == EOF, message);
}

void flush_line(void)
{
  if (line_len > 0)
    fputs(line, fpw);
}

void terminate(bool condition, const char *message)
{
  if (condition)
  {
    fprintf(stderr, "%s", message);
    exit(EXIT_FAILURE);
  }
}