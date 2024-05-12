/*
Write a program named fcat that "concatenates" any number of files by writing them to
standard output, one after the other, with no break between files. For example, the following
command will display the files f1.c, f2.c and f3.c on the screen:

fcat f1.c f2.c f3.c

fcat should issue an error message if any file can't be opened. Hint: Since it has no more
than one file open at a time, fcat needs only a single file pointer variable. Once it's fin-
ished with a file fcat can use the same variable when it opens the next file.
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_MESSAGE_SIZE 255

void terminate(bool condition, const char *message);

int main(int argc, char *argv[])
{
  terminate(argc < 2, "Not enough arguments. Supply 1 or more files, e.g. fcat f1.c f2.c f3.c\n");

  FILE *fp = NULL;
  long int file_size = 0L;
  char *file_contents = NULL;
  char message[MAX_MESSAGE_SIZE];

  for (int i = 1; i < argc; ++i)
  {
    snprintf(message, MAX_MESSAGE_SIZE, "Error in main: failed to open %s for reading.\n", argv[i]);
    terminate((fp = fopen(argv[i], "r")) == NULL, message);

    snprintf(message, MAX_MESSAGE_SIZE, "Error in main: failed to seek to end of %s\n", argv[i]);
    terminate((fseek(fp, 0L, SEEK_END) != 0), message);

    snprintf(message, MAX_MESSAGE_SIZE, "Error in main: failed to get the size of %s\n", argv[i]);
    terminate((file_size = ftell(fp)) == -1, message);

    snprintf(message, MAX_MESSAGE_SIZE, "Error in main: failed to seek to beginning of %s\n", argv[i]);
    terminate((fseek(fp, 0L, SEEK_SET) != 0), message);

    snprintf(message, MAX_MESSAGE_SIZE, "Error in main: failed to allocate memory to read the contents of %s\n", argv[i]);
    terminate(((file_contents = malloc(file_size + 1)) == NULL), message);

    size_t result = fread(file_contents, 1, file_size, fp);

    if (result == (size_t)file_size)
    {
      file_contents[result] = '\0';
      fprintf(stdout, "%s", file_contents);
    }

    snprintf(message, MAX_MESSAGE_SIZE, "Error in main: unexpected EOF whilst reading %s\n", argv[i]);
    terminate(feof(fp), message);
    snprintf(message, MAX_MESSAGE_SIZE, "Error in main: error whilst reading %s\n", argv[i]);
    terminate(ferror(fp), message);

    free(file_contents);
    snprintf(message, MAX_MESSAGE_SIZE, "Error in main: failed to properly close %s\n", argv[i]);
    terminate(fclose(fp) == EOF, message);
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