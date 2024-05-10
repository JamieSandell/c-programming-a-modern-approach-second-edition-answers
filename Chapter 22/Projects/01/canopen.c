/*
Extend the canopen.c program of Section 22.2 so that the user may put any number of
file names on the command line:

canopen foo bar baz

The program should print a separate can be opened or can't be opened message for
each file. Have the program terminate with status EXIT_FAILURE if one or more of the
files can't be opened.
*/

/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King                                         *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.                                  *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.      *
 *********************************************************/

/* canopen.c (Chapter 22, page 547) */
/* Checks whether a file can be opened for reading */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  FILE *fp;

  if (argc != 2) {
    printf("usage: canopen filename\n");
    exit(EXIT_FAILURE);
  }

  for (int i = 0; i < argc; ++i)
  {
    if ((fp = fopen(argv[i], "r")) == NULL) {
        printf("%s can't be opened\n", argv[i]);
        exit(EXIT_FAILURE);
      }
  }  

  printf("%s can be opened\n", argv[1]);
  fclose(fp);
  return 0;
}
