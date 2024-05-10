/*
Write a program that converts all letters in a file to upper case (Characters other than letters
shouldn't be changed). The program should obtain the file name from the command line and
write its output to stdout.
*/

#include <stdio.h>
#include <stdlib.h>

#define MESSAGE_SIZE 100

void terminate(const char *message);

int main(int argc, char *argv[])
{
  char message[MESSAGE_SIZE];

  if (argc != 2)
  {
    terminate("Error in main: argument usage incorrect. Correct usage example: main file.txt\n");
  }

  FILE *fp;

  if ((fp = (fopen(argv[1], "r+w"))) == NULL)
  {
    snprintf(message, MESSAGE_SIZE, "Error in main: failed to open %s for read + write.\n", argv[1]);
    terminate(message);
  }

  fclose(fp);

  if (feof(fp))
  {
    snprintf(message, MESSAGE_SIZE, "Error in main: failed to close %s properly, EOF.\n", argv[1]);
    terminate(message);
  }

  if (fseek(fp, 0L, SEEK_END) != 0)
  {
    
  }

  long file_size = ftell(fp);

  return EXIT_SUCCESS;
}

void terminate(const char *message)
{
  fprintf(stderr, "%s", message);
  exit(EXIT_FAILURE);
}