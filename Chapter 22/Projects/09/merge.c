/*
Write a program that merges two files containing part records stored by the inventory.c
program (see Programming Project 8). Assume that the records in each file are sorted by
part number, and that we want the resulting file to be sorted as well. If both files have a part
with the same number, combine the quantities stored in the records (As a consistency
check, have the program compare the part names and print an error message if they don't
match). Have the program obtain the names of the input files and the merged file from the
command line.
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILE_SIZE 255
#define MAX_MESSAGE_SIZE 512
#define MAX_PARTS 100
#define MAX_PART_NAME_LENGTH 25

char g_message[MAX_MESSAGE_SIZE];
unsigned int g_num_parts_read = 0;

struct part {
  int number;
  char name[MAX_PART_NAME_LENGTH + 1];
  int on_hand;
} inventory[MAX_PARTS * 2];

size_t read_parts_file(void *restrict buffer, const char *filename);
void terminate(bool condition, const char *message);

int main(int argc, char *argv[])
{
    terminate(argc != 4, "Error: Incorrect usage. Example usage: merge inventory1.dat inventory2.dat merged_inventory.dat\n");

    return EXIT_SUCCESS;
}

size_t read_parts_file(void *restrict buffer, const char *filename)
{
    FILE *fpr = fopen(filename, "rb");

    snprintf(g_message, MAX_MESSAGE_SIZE, "Error opening %s for reading.\n", filename);
    terminate(fpr == NULL, g_message);
    size_t num_parts_read = fread(&inventory[g_num_parts_read], sizeof(struct part), MAX_PARTS, fpr);

    if (num_parts_read != MAX_PARTS)
    {
        snprintf(g_message, MAX_MESSAGE_SIZE, "Error reading %s\n", filename);
        terminate(feof(fpr) == 0 && ferror(fpr), g_message);
    }

    snprintf("Failed to close %s properly.\n", fpr);
    terminate(fclose(fpr) == EOF, g_message);

    ++g_num_parts_read;
}

void terminate(bool condition, const char *message)
{
    if (condition)
    {
        fprintf(stderr, message);
        exit(EXIT_FAILURE);
    }
}