/*
Write a program that simulates the game of craps, which is played with two dice. On the
first roll, the player wins if the sum of the dice is 7 or 11. The player loses if the sum is 2, 3,
or 12. Any other roll is called the "point" and the game continues. On each subsequent roll,
the player wins if he or she rolls the point again. The player loses by rolling 7. Any other roll
is ignored and the game continues. At the end of each game, the program will ask the user
whether or not to play again. When the user enters a response other than y or Y, the program
will display the number of wins and losses then terminate.

You rolled: 8
Your point is 8
You rolled: 3
You rolled: 10
You rolled: 8
You win!

Play again? y

You rolled: 6
Your point is 6
You rolled: 5
You rolled: 12
You rolled: 3
You rolled: 7
You lose!

Play again? y

You rolled: 11
You win!

Play again? n

Wins: 2  Losses: 1
Write your program as three functions: main, roll_dice and play_game. Here are the
prototypes for the latter two functions:

int roll_dice(void);
bool play_game{void);

roll_dice should generate two random numbers, each between 1 and 6, and return their
sum. play_game should play one craps game (calling roll_dice to determine the out-
come of each dice roll); it will return true if the player wins and false if the player loses.
play_game is also responsible for displaying messages showing the results of the player's
dice rolls. main will call play_game repeatedly keeping track of the number of wins and losses and
displaying the "you win" and "you lose" messages. Hint: Use the rand function
to generate random numbers. See the deal.c program in Section 8.2 for an example
of how to call rand and the related srand function.
*/

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_dice(void);
bool play_game(void);

int main(void)
{
    int wins = 0;
    int losses = 0;
    char c;
    bool result;
    int scanf_result;

    srand((unsigned)time(NULL));

    do
    {
        result = play_game();

        if (result)
        {
            wins++;
            printf("You win!\n\n");
        }
        else
        {
            losses++;
            printf("You lose!\n\n");
        }
        
        printf("Play again? ");
        scanf_result =scanf(" %c", &c);

        if (scanf_result == 0)
        {
            scanf("%*[^\n]"); // clear newline from the buffer
        }

    } while (toupper(c) == 'Y');

    printf("Wins: %d Losses: %d\n", wins, losses);

    exit(EXIT_SUCCESS);
}

int roll_dice(void)
{
    return ((rand() % 6) + 1) + ((rand() % 6) + 1);
}

bool play_game(void)
{
    bool game_over = false;
    int dice_roll = roll_dice();
    int point;
    bool won;

    printf("You rolled: %d\n", dice_roll);

    switch(dice_roll)
    {
        case 7: // fall-through
        case 11:
        {
            return true;
        }
        case 2: // fall-through
        case 3: // fall-through
        case 12:
        {
            return false;
        }
        default:
        {
            point = dice_roll;
            break;
        }
    }

    while (!game_over)
    {
        dice_roll = roll_dice();
        printf("You rolled: %d\n", dice_roll);

        if (dice_roll == point)
        {
            won = true;
            game_over = true;
        }
        else if(dice_roll == 7)
        {
            won = false;
            game_over = true;
        }
    }

    return won;
}