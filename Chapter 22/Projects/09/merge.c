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
#include <string.h>

#define MAX_FILE_SIZE 255
#define MAX_MESSAGE_SIZE 512
#define MAX_PARTS 100
#define MAX_PART_NAME_LENGTH 25

char g_message[MAX_MESSAGE_SIZE];

struct part {
  int number;
  char name[MAX_PART_NAME_LENGTH + 1];
  int on_hand;
};

int part_comparator(const void *v1, const void *v2);
size_t read_parts_file(struct part *buffer, const char *filename);
void terminate(bool condition, const char *message);

int main(int argc, char *argv[])
{
    terminate(argc != 4, "Error: Incorrect usage. Example usage: merge inventory1.dat inventory2.dat merged_inventory.dat\n");
    struct part inventory1[MAX_PARTS];
    size_t num_parts_inv1 = read_parts_file(inventory1, argv[1]);
    struct part inventory2[MAX_PARTS];
    size_t num_parts_inv2 = read_parts_file(inventory2, argv[2]);
    size_t num_merged_parts_inv = num_parts_inv1 + num_parts_inv2;
    struct part merged_inventory[MAX_PARTS * 2];
    bool found_part = false;
    memcpy(merged_inventory, inventory1, sizeof(struct part) * num_parts_inv1);
    size_t merged_parts_count = num_parts_inv1;

    for (size_t merged_inventory_index = 0; merged_inventory_index < num_parts_inv1; ++merged_inventory_index)
    {
        for (size_t inventory2_index = 0; inventory2_index < num_parts_inv2; ++inventory2_index)
        {
            if (merged_inventory[merged_inventory_index].number = inventory2[inventory2_index].number)
            {
                snprintf
                (
                    g_message,
                    MAX_MESSAGE_SIZE,
                    "Error: Part name mismatch (%s vs %s) for part number %d of %s and %s\n",
                    
                )
                terminate(merged_inventory[merged_inventory_index].name != inventory2[inventory2_index].name, g_message);
            }
        }
        
    }
    
    
    
    
    
    qsort(merged_inventory, sizeof(struct part), num_merged_parts_inv, part_comparator);
    
    return EXIT_SUCCESS;
}

int part_comparator(const void *v1, const void *v2)
{
    const struct part *p1 = (struct part *)v1;
    const struct part *p2 = (struct part *)v2;

    if (p1->number < p2->number)
    {
        return -1;
    }
    else if(p1->number > p2->number)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

size_t read_parts_file(struct part *buffer, const char *filename)
{
    FILE *fpr = fopen(filename, "rb");

    snprintf(g_message, MAX_MESSAGE_SIZE, "Error opening %s for reading.\n", filename);
    terminate(fpr == NULL, g_message);
    size_t num_parts_read = fread(buffer, sizeof(struct part), MAX_PARTS, fpr);

    if (num_parts_read != MAX_PARTS)
    {
        snprintf(g_message, MAX_MESSAGE_SIZE, "Error reading %s\n", filename);
        terminate(feof(fpr) == 0 && ferror(fpr), g_message);
    }

    snprintf(stderr, "Failed to close %s properly.\n", fpr);
    terminate(fclose(fpr) == EOF, g_message);

    return num_parts_read;
}

void terminate(bool condition, const char *message)
{
    if (condition)
    {
        fprintf(stderr, message);
        exit(EXIT_FAILURE);
    }
}