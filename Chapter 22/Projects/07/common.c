#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "common.h"

char g_message[MAX_MESSAGE_SIZE];

/// @brief Prints the message and terminates the program if the condition is true.
/// @param condition 
/// @param message 
void terminate(bool condition, const char *message)
{
    if (condition)
    {
        printf("%s", message);
        exit(EXIT_FAILURE);
    }
}