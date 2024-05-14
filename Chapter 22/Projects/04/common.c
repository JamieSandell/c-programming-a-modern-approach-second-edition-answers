#include <stdio.h>
#include <stdlib.h>
#include "common.h"

char g_message_buffer[MAX_MESSAGE_SIZE];

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