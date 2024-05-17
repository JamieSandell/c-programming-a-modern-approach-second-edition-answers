/*
The xor.c program of Section 20.1 refuses to encrypt bytes that -- in original or encrypted
form -- are control characters. We can now remove this restriction. Modify the program so
that the names of the input and output files are command-line arguments. Open both files in
binary mode, and remove the test that checks whether the original and encrypted characters
are printing characters.
*/

/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King                                         *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.                                  *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.      *
 *********************************************************/

/* xor.c (Chapter 20, page 515) */
/* Performs XOR encryption */

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define KEY '&'
#define MAX_MESSAGE_SIZE 255

void terminate(bool condition, const char *message);

int main(int argc, char *argv[])
{
  terminate(argc != 3, "Invalid usage. Correct usage example: xor input.bin output.bin\n");

  FILE *fpr = fopen(argv[1], "rb");
  char message[MAX_MESSAGE_SIZE];

  snprintf(message, MAX_MESSAGE_SIZE, "Failed to open %s for reading.\n", argv[1]);
  terminate(ferror(fpr), message);

  FILE *fpw = fopen(argv[2], "wb");

  snprintf(message, MAX_MESSAGE_SIZE, "Failed to create/open %s for writing.\n", argv[2]);
  terminate(ferror(fpw), message);

  int orig_char, new_char;

  while ((orig_char = fgetc(fpr)) != EOF) {
    new_char = orig_char ^ KEY;
    fputc(new_char, fpw);

    if (ferror(fpw))
    {
      printf("Error whilst writing to %s\n", argv[2]);
      snprintf(message, MAX_MESSAGE_SIZE, "Failed to close %s properly.\n", argv[1]);
      terminate(fclose(fpr), message);
      break;
    }
  }

  snprintf(message, MAX_MESSAGE_SIZE, "Failed to close %s properly.\n", argv[1]);
  terminate(fclose(fpr), message);
  snprintf(message, MAX_MESSAGE_SIZE, "Failed to close %s properly.\n", argv[2]);
  terminate(fclose(fpw), message);

  return EXIT_SUCCESS;
}

void terminate(bool condition, const char *message)
{
  if (condition)
  {
    printf(message);
    exit(EXIT_FAILURE);
  }
}
