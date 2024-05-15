#ifndef COMMON_H
#define COMMON_H

#include <stdbool.h>

#define MAX_MESSAGE_SIZE 255

extern char g_message_buffer[];

void close_file(FILE *fp);
FILE *open_file_for_reading(const char *file);
void terminate(bool condition, const char *message);

#endif