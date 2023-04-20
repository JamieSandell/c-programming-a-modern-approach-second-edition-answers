/*
The prototypical Internet newbie is a fellow named BIFF, who has a unique way of writing
messages. Here's a typical BIFF communiqué:

H3Y DUD3, C 15 R1LLY C00L!!!!!!!!!!
Write a "BIFF filter" that reads a message entered by the user and translates it into BIFF-
speak:

Enter message: Hey dude, C is rilly cool
In B1FF-speak: H3Y DUD3, C 15 R1LLY C00L!!!!!!!!!!

Your program should convert the message to upper-case letters, substitute digits for certain
letters (A→4, B→8, E→3, I→1, O→0, S→5), and then append 10 or so exclamation marks.
Hint: Store the original message in an array of characters, then go back through the array, translating and printing characters one by one.

Solution
*/

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int main(void)
{
    int char_count = 0;
    char c;
    char original_message[BUFFER_SIZE];    

    printf("Enter message: ");
    printf("In B1FF-speak: ");
    
    while ((c = getchar()) != '\n' && char_count < BUFFER_SIZE)
    {
        if (c >= 'a' && c <= 'z') // convert to upper-case
        {
            c -= 32;
        }
        original_message[char_count++] = c;
    }

    for (int i = 0; i < char_count; i++)
    {
        c = original_message[i];
        switch (c)
        {
            case 'A':
            {
                c = '4';
                break;
            }
            case 'B':
            {
                c = '8';
                break;
            }
            case 'E':
            {
                c = '3';
                break;
            }
            case 'I':
            {
                c = '1';
                break;
            }
            case 'O':
            {
                c = '0';
                break;
            }
            case 'S':
            {
                c = '5';
                break;
            }
            default:
            {
                break;
            }
        }
        printf("%c", c);
    }
    printf("!!!!!!!!!!\n");

    return EXIT_SUCCESS;
}