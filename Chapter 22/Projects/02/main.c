/*
Write a program that converts all letters in a file to upper case (Characters other than letters
shouldn't be changed). The program should obtain the file name from the command line and
write its output to stdout.
*/

#include <ctype.h>
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

  if (feof(fp))
  {
    snprintf(message, MESSAGE_SIZE, "Error in main: failed to close %s properly, EOF.\n", argv[1]);
    terminate(message);
  }

  if (fseek(fp, 0L, SEEK_END) != 0)
  {
    snprintf(message, MESSAGE_SIZE, "Error in main: failed to seek to the end of %s\n", argv[1]);
    terminate(message);
  }

  long file_size = ftell(fp);

  if (file_size < 0L)
  {
    snprintf(message, MESSAGE_SIZE, "Error in main: failed to get the filesize of %s\n", argv[1]);
    terminate(message);
  }

  char *file_contents;

  if ((file_contents = malloc(sizeof(char) * file_size)) == NULL)
  {
    printf(message, MESSAGE_SIZE, "Error in main: failed to allocate memory.\n");
    terminate(message);
  }

  if (fseek(fp, 0L, SEEK_SET) != 0)
  {
    snprintf(message, MESSAGE_SIZE, "Error in main: failed to seek to the start of the of %s\n", argv[1]);
    terminate(message);
  }

  size_t new_size = fread(file_contents, sizeof(char), file_size, fp);

  if (ferror(fp) != 0)
  {
    snprintf(message, MESSAGE_SIZE, "Error in main: failed to read %s into the buffer.\n", argv[1]);
    terminate(message);
  }

  fclose(fp);

  for (size_t i = 0; i < new_size; ++i)
  {
    fprintf(stdout, "%c", toupper(file_contents[i]));
  }

  if (file_contents)
  {
    free(file_contents);
  }

  return EXIT_SUCCESS;
}

void terminate(const char *message)
{
  fprintf(stderr, "%s", message);
  exit(EXIT_FAILURE);
}