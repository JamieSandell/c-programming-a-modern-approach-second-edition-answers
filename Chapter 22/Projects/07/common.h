#ifndef COMMON_H

#define COMMON_H

#include <stdbool.h>

#define MAX_MESSAGE_SIZE 255

extern char g_message[];

void terminate(bool command, const char *message);

#endif