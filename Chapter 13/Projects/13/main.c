/*
Modify Programming Project 15 from Chapter 8 so that it includes the following function:

void encrypt(char *message, int shift);

The function expects message to point to a string containing the message to be encrypted;
shift represents the amount by which each letter in the message is to be shifted.
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

#include <stdio.h>
#include <stdlib.h>

#define LENGTH 80

void encrypt(char *message, int shift);

int main(void)
{
    char message[LENGTH] = {0};
    char c;
    int char_count = 0;
    int shift_amount;

    printf("Enter message to be encrypted: ");
    
    while ((c = getchar()) != '\n' && char_count < LENGTH + 1 && c != EOF)
    {
        message[char_count++] = c;
    }
    message[char_count] = '\0';

    printf("Enter shift amount (1 - 25): ");
    scanf("%d", &shift_amount);

    printf("Encrypted message: ");
    encrypt(message, shift_amount);
    printf("%s\n", message);

    return EXIT_SUCCESS;
}

void encrypt(char *message, int shift)
{
    while (*message)
    {
        if (*message >= 'A' && *message <= 'Z')
        {
            *message = ((*message - 'A') + shift) % 26 + 'A';
        }
        else if (*message >= 'a' && *message <= 'z')
        {
            *message = ((*message - 'a') + shift) % 26 + 'a';
        }

        ++message;
    }
}