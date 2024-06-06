/*
Modify Programming Project 15 from Chapter 8 so that the program prompts the user to
enter the name of a file containing the message to be encrypted:

Enter name of file to be encrypted: message.txt
Enter shift amount (1-25): 3

The program then writes the encrypted message to a file with the same name but an added
extension of .enc. In this example, the original file name is message.txt, so the
encrypted message will be stored in a file named message.txt.enc. There's no limit on
the size of the file to be encrypted or on the length of each line in the file.
*/

/*
One of the oldest known encrpytion techniques is the Caesar cipher, attributed to Julius Cae-
sar. It involves replacing each letter in a message with another letter that is a fixed number of
positions later in the alphabet. (If the replacement would go past the letter Z, the cipher
"wraps around" to the beginning of the alphabet. For example, if each letter is replaced by
the letter two positions after it, the Y would be replaced by A, and Z would be replaced by
B.) Write a program that encrypts a message using a Caesar cipher. The user will enter the
message to be encrypted and the shift amount (the number of positions by which letters
should be shifted):

Enter message to be encrypted: Go ahead, make my day.
Enter shift amount (1-25): 3
Encrypted message: Jr dkhdg, pdnh pb gdb.

Notice that the program can decrypt a message if the user enters 26 minus the original key:

Enter message to be encrypted: Jr dkhdg, pdnh pb gdb.
Enter shift amount (1-25): 23
Encrypted message: Go ahead, make my day.

You may assume that the message does not exceed 80 characters. Characters other than let-
ters should be left unchanged. Lower-case letters remain lower-case when encrypted, and
upper-case letters remain upper-case. Hint: To handle the wrap-around problem, use the
expression ((ch - 'A') + n) % 26 + 'A' to calculate the encrypted version of an upper-
case letter, where ch stores the letter and n stores the shift amount. (You'll need a similar
expression for lower-case letters.)
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 255
#define MAX_MESSAGE_LENGTH 512
#define ENC_LENGTH 4

void terminate(bool condition, const char *message);

int main(void)
{
    printf("Enter the name of file to be encrypted: ");
    int c;
    int count = 0;
    char unencrypted_filename[MAX_FILENAME_LENGTH - ENC_LENGTH + 1];
    char message[MAX_MESSAGE_LENGTH];
    
    for (;;)
    {
        c = getchar();

        if (c == EOF || c == '\n')
        {
            break;
        }

        unencrypted_filename[count] = c;
        ++count;
        snprintf(message, MAX_MESSAGE_LENGTH, "Error: Max filename length (%d) exceeded.\n", MAX_FILENAME_LENGTH - ENC_LENGTH);
        terminate(count == MAX_FILENAME_LENGTH - ENC_LENGTH, message);
    }
    
    unencrypted_filename[count] = '\0';

    FILE *fpr = fopen(unencrypted_filename, "r");
    snprintf(message, MAX_MESSAGE_LENGTH, "Error: failed to open %s for reading.\n", unencrypted_filename);
    terminate(fpr == NULL, message);

    snprintf(message, MAX_MESSAGE_LENGTH, "Error seeking to the end of %s\n", unencrypted_filename);
    terminate(fseek(fpr, 0L, SEEK_END), message);

    long file_size = ftell(fpr);
    snprintf(message, MAX_MESSAGE_LENGTH, "Error: failed to get size of %s\n", unencrypted_filename);
    terminate(file_size == -1L, message);

    snprintf(message, MAX_MESSAGE_LENGTH, "Error: failed to seek to the beginning of %s\n", unencrypted_filename);
    terminate(fseek(fpr, 0L, SEEK_SET), message);

    char *file_contents = malloc((size_t) file_size);
    terminate(file_contents == NULL, "Error: failed to allocate memory.\n");

    snprintf(message, MAX_MESSAGE_LENGTH, "Error reading contents of %s\n", unencrypted_filename);
    terminate(fread(file_contents, 1, file_size, fpr) != (size_t)file_size, message);

    printf("Enter shift amount (1 - 25): ");
    int shift_amount;
    scanf("%d", &shift_amount);
    char encrypted_filename[MAX_FILENAME_LENGTH + 1];
    strcpy(encrypted_filename, unencrypted_filename);
    strcat(encrypted_filename, ".enc");
    
    FILE *fpw = fopen(encrypted_filename, "w");
    snprintf(message, MAX_MESSAGE_LENGTH, "Error opening %s for writing.\n", encrypted_filename);
    terminate(fpw == NULL, message);

    snprintf(message, MAX_MESSAGE_LENGTH, "Error writing to %s\n", encrypted_filename);

    for (int i = 0; i < file_size; ++i)
    {
        if ((file_contents[i] < 'A' || file_contents[i] > 'Z') && (file_contents[i] < 'a' || file_contents[i] > 'z'))
        {
            terminate(fputc(file_contents[i], fpw) == EOF, message);
            continue;
        }

        if (file_contents[i] >= 'A' && file_contents[i] <= 'Z')
        {
            c = ((file_contents[i] - 'A') + shift_amount) % 26 + 'A';
        }
        else
        {
            c = ((file_contents[i] - 'a') + shift_amount) % 26 + 'a';
        }

        terminate(fputc(c, fpw) == EOF, message);
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