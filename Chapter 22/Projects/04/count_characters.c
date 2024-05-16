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

  FILE *fp = open_file_for_reading(argv[1]);

  unsigned int count = 0;
  int c;

  while ((c = fgetc(fp)) != EOF)
  {
    ++count;
  }

  snprintf(g_message_buffer, MAX_MESSAGE_SIZE, "Failed to read %s\n", argv[1]);
  terminate(ferror(fp), g_message_buffer);

  printf("%d characters read from %s\n", count, argv[1]);

  close_file(fp);

  return EXIT_SUCCESS;
}