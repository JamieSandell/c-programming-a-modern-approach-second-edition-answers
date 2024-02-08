/*
Write a function that, given a string as its argument, searches the following array of
structures for a matching command name, then calls the function associated with that name.

struct {
    char *cmd_name;
    void (*cmd_pointer) (void);
} file_cmd[] = {
    {"new",         new_cmd},
    {"open",        open_cmd},
    {"close",       close_cmd},
    {"close all",   close_all_cmd},
    {"save",        save_cmd},
    {"save as",     save_as_cmd},
    {"save all",    save_all_cmd},
    {"print",       print_cmd},
    {"exit",        exit_cmd}
};
*/

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void new_cmd(void);
void open_cmd(void);
void close_cmd(void);
void close_all_cmd(void);
void save_cmd(void);
void save_as_cmd(void);
void save_all_cmd(void);
void print_cmd(void);
void exit_cmd(void);
void print_message(const char *message);
void call_cmd(const char *cmd);

#define FILE_CMD_SIZE sizeof(file_cmd) / sizeof(file_cmd[0])

struct
{
    char *cmd_name;
    void (*cmd_pointer) (void);
} file_cmd[] =
{
    {"new",         new_cmd},
    {"open",        open_cmd},
    {"close",       close_cmd},
    {"close all",   close_all_cmd},
    {"save",        save_cmd},
    {"save as",     save_as_cmd},
    {"save all",    save_all_cmd},
    {"print",       print_cmd},
    {"exit",        exit_cmd}
};

int main(void)
{
    int input;

    while (true)
    {
        for (int i = 0; (size_t)i < FILE_CMD_SIZE; ++i)
        {
            printf("[%d] : %s\n", i, file_cmd[i].cmd_name);
        }
        printf("Enter a command to execute, e.g. 0 for new, 99 to quit: ");
        scanf("%d", &input);

        if (input == 99)
        {
            return EXIT_SUCCESS;
        }
        else if (input < 0 || (size_t)input >= FILE_CMD_SIZE)
        {
            printf("Invalid selection.\n");
        }
        else
        {
            call_cmd(file_cmd[input].cmd_name); 
        }           
    }
    

    return EXIT_SUCCESS;
}

void new_cmd(void)
{
    print_message("Called new_cmd.");
}

void open_cmd(void)
{
    print_message("Called open_cmd.");
}

void close_cmd(void)
{
    print_message("Called close_cmd.");
}

void close_all_cmd(void)
{
    print_message("Called close_all_cmd.");
}

void save_cmd(void)
{
    print_message("Called save_cmd.");
}

void save_as_cmd(void)
{
    print_message("Called save_as_cmd.");
}

void save_all_cmd(void)
{
    print_message("Called save_all_cmd.");
}

void print_cmd(void)
{
    print_message("Called print_cmd.");
}

void exit_cmd(void)
{
    print_message("Called exit_cmd.");
}

void print_message(const char *message)
{
    printf("%s\n", message);
}

void call_cmd(const char *cmd)
{
    for (size_t i = 0; i < FILE_CMD_SIZE; ++i)
    {
        if (strcmp(file_cmd[i].cmd_name, cmd) == 0)
        {
            file_cmd[i].cmd_pointer();
        }
    }
}