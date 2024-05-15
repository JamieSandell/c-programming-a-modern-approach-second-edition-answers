#include <stdio.h>
#include <stdlib.h>
#include "common.h"

char g_message_buffer[MAX_MESSAGE_SIZE];

/// @brief Open a file for reading. Terminates on error.
/// @param file 
/// @return Pointer to the opened file.
FILE *open_file_for_reading(const char *file)
{
    FILE *fp = fopen(file, "r");
    snprintf(g_message_buffer, MAX_MESSAGE_SIZE, "Failed to open %s for reading.\n", file);
    terminate(fp == NULL, g_message_buffer);

    return fp;
}

void close_file(FILE *fp)
{
    printf("Failed to close the file properly.\n");
    terminate(fclose(fp) != 0, g_message_buffer);
}

/// @brief If the condition is true, print the message to stderr and exit.
/// @param condition 
/// @param message 
void terminate(bool condition, const char *message)
{
    if (condition)
    {
        fprintf(stderr, "%s", message);
        exit(EXIT_FAILURE);
    }    
}