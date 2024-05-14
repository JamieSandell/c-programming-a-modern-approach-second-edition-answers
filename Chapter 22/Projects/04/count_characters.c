/*
(a) Write a program that counts the number of characters in a text file.

(b) Write a program that counts the number of words in a text file (A "word" is any
sequence of non-white-space characters).

(c) Write a program that counts the number of lines in a text file.

Have each program obtain the file name from the command line.
*/

#include <stdio.h>
#include <stdlib.h>
#include "common.h"

int main(int argc, char *argv[])
{
  terminate(argc != 2, "Program usage: count_characters file.txt");

  FILE *fp = fopen(argv[1], "r");
  snprintf(g_message_buffer, MAX_MESSAGE_SIZE, "Failed to open %s for reading.\n", argv[1]);
  terminate(fp == NULL, g_message_buffer);

  snprintf(g_message_buffer, MAX_MESSAGE_SIZE, "Failed to close %s properly.\n", argv[1]);
  terminate(fclose(fp) != 0, g_message_buffer);

  return EXIT_SUCCESS;
}