
/*
Modify the fcopy.c program of Section 22.4 so that is uses fread and fwrite to copy
the file in blocks of 512 bytes (The last block may contain fewer than 512 bytes, of course.)
*/

/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King                                         *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.                                  *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.      *
 *********************************************************/

/* fcopy.c (Chapter 22, page 568) */
/* Copies a file */

#include <stdio.h>
#include <stdlib.h>

#define BLOCK 512

int main(int argc, char *argv[])
{
  FILE *source_fp, *dest_fp;

  if (argc != 3) {
    fprintf(stderr, "usage: fcopy source dest\n");
    exit(EXIT_FAILURE);
  }

  if ((source_fp = fopen(argv[1], "rb")) == NULL) {
    fprintf(stderr, "Can't open %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  if ((dest_fp = fopen(argv[2], "wb")) == NULL) {
    fprintf(stderr, "Can't open %s\n", argv[2]);
    fclose(source_fp);
    exit(EXIT_FAILURE);
  }

   size_t bytes_read;
   char buffer[BLOCK];

   for (;;)
   {
    if ((bytes_read = fread(buffer, 1, BLOCK, source_fp)) != BLOCK)
    {
      if (ferror(source_fp))
      {
        fprintf(stderr, "Error reading from %s", argv[1]);
        fclose(source_fp);
        exit(EXIT_FAILURE);
      }

      if (fwrite(buffer, 1, bytes_read, dest_fp) != bytes_read)
      {
        fprintf(stderr, "Error writing to %s\n", argv[2]);
        fclose(dest_fp);
        exit(EXIT_FAILURE);
      }
    }

    if (feof(source_fp))
    {
      break;
    }
   }

  fclose(source_fp);
  fclose(dest_fp);
  return 0;
}
