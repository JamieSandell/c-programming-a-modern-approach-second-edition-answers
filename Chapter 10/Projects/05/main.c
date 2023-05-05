/*
Modify the poker.c program of Section 10.5 by allowing "ace-low" straights (ace, two,
three, four, five).
*/

// Classifies a poker hand

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5

// external variables
bool straight, flush, four, three, royal;
int pairs; // can be 0, 1, or 2

// prototypes
void read_cards(int hand[][2]);
void analyze_hand(int hand[][2]);
void print_result(void);

/**********************************************************
 * main: Calls read_cards, analyse_hand, and print_result *
 *       repeatedly.                                      *
 **********************************************************/
int main(void)
{
    int hand[NUM_CARDS][2];

    for (;;)
    {
        read_cards(hand);
        analyze_hand(hand);
        print_result();
    }
}

/**********************************************************
 * read_cards: Reads the cards into the external          *
 *             variables num_in_rank and num_in_suit;     *
 *             Checks for bad cards and duplicate cards.  *
 **********************************************************/
void read_cards(int hand[][2])
{
    char ch, rank_ch, suit_ch;
    bool bad_card;
    int cards_read = 0;
    int rank, suit;

    for (rank = 0; rank < NUM_CARDS; rank++)
    {
        for (suit = 0; suit < 2; suit++)
        {
            hand[rank][suit] = 0;
        }
    }

    while (cards_read < NUM_CARDS)
    {
        bad_card = false;

        printf("Enter a card: ");

        rank_ch = getchar();
        
        switch (rank_ch)
        {
            case '0':
            {
                exit(EXIT_SUCCESS);
            }
            case '2':
            {
                rank = 0;
                break;
            }
            case '3':
            {
                rank = 1;
                break;
            }
            case '4':
            {
                rank = 2;
                break;
            }
            case '5':
            {
                rank = 3;
                break;
            }
            case '6':
            {
                rank = 4;
                break;
            }
            case '7':
            {
                rank = 5;
                break;
            }
            case '8':
            {
                rank = 6;
                break;
            }
            case '9':
            {
                rank = 7;
                break;
            }
            case 't': // fall-through
            case 'T':
            {
                rank = 8;
                break;
            }
            case 'j': // fall-through
            case 'J':
            {
                rank = 9;
                break;
            }
            case 'q': // fall-through
            case 'Q':
            {
                rank = 10;
                break;
            }
            case 'k': // fall-through
            case 'K':
            {
                rank = 11;
                break;
            }
            case 'a': // fall-through
            case 'A':
            {
                rank = 12;
                break;
            }
            default:
            {
                bad_card = true;
                break;
            }
        }

        suit_ch = getchar();

        switch (suit_ch)
        {
            case 'c': // fall-through
            case 'C':
            {
                suit = 0;
                break;
            }
            case 'd': // fall-through
            case 'D':
            {
                suit = 1;
                break;
            }
            case 'h': // fall-through
            case 'H':
            {
                suit = 2;
                break;
            }
            case 's': // fall-through
            case 'S':
            {
                suit = 3;
                break;
            }
            default:
            {
                bad_card = true;
            }
        }

        while ((ch = getchar()) != '\n')
        {
            if (ch != ' ')
            {
                bad_card = true;
            }
        }

        if (bad_card)
        {
            printf("Bad card; ignored.\n");
        }
        else if (hand[cards_read][0] && hand[cards_read][1]/*card_exists[rank][suit]*/)
        {
            printf("Duplicate card; ignored.\n");
        }
        else
        {
            hand[cards_read][0] = rank;
            hand[cards_read][1] = suit;
            cards_read++;
        }
    }
}

/**********************************************************
 * analyze_hand: Determines whether the hand contains a   *
 *               straight, a flush, four-of-a-kind,       *
 *               and/or three-of-a-kind; determines the   *
 *               number of pairs; stores the results into *
 *               the external variables straight, flush,  *
 *               four, three, and pairs.                  *
 **********************************************************/
void analyze_hand(int hand[][2])
{
    straight = false;
    flush = false;
    four = false;
    three = false;
    royal = false;
    int matches = 0;
    int num_sec = 0;

    // sort the cards with selection sort
    int smallest, temp_suit, temp_rank;
    for (int i = 0; i < NUM_CARDS; i++)
    {
        smallest = i;

        for (int j = i + 1; j < NUM_CARDS; j++)
        {
            if (hand[j][0] < hand[smallest][0])
            {
                smallest = j;
            }                
        }

        temp_rank         = hand[i][0];
        temp_suit         = hand[i][1];
        hand[i][0]        = hand[smallest][0];
        hand[i][1]        = hand[smallest][1];
        hand[smallest][0] = temp_rank;
        hand[smallest][1] = temp_suit;
    }

    // check for royal
    for (int card = 0; card < NUM_CARDS; card++)
    {
        if (hand[card][0] != card + 8) // Ten = rank 8...Ace = rank 12
        {
            break;
        }

        if (card == NUM_CARDS - 1)
        {
            royal = true;
        }
    }

    // check for flush
    for (int card = 1; card < NUM_CARDS; card++)
    {
        if (hand[card][1] != hand[0][1])
        {
            break;
        }

        if (card == NUM_CARDS - 1)
        {
            flush = true;
        }
    }

    // checks for straight
    for (int card = 1; card < NUM_CARDS; card++)
    {
        if (num_sec == 4 && hand[card][0] == 12)
        {
            straight = true;
        }

        if (hand[card][0] - hand[card-1][0] != 1)
        {
            break;
        }

        num_sec++;

        if (card == NUM_CARDS - 1)
        {
            straight = true;
        }
    }

    // check for 4-of-a-ind, 3-of-a-kind and pairs
    for (int i = 0; i < NUM_CARDS; i++)
    {
        matches = 0;
        for (int j = i + 1; j < NUM_CARDS; j++)
        {
            if (hand[j][0] == hand[i][0])
            {
                matches++;
            }
        }

        if (matches == 1) pairs++;
        if (matches == 2) three = true;
        if (matches == 3) four = true;
    }
}

/**********************************************************
 * print result: Prints the classification of the hand,   *
 *               based on the values of the external      *
 *               variables straight, flush, four, three,  *
 *               and pairs.
 **********************************************************/
void print_result(void)
{
    if (royal && straight && flush)
    {
        printf("Royal flush");
    }
    if (straight && flush)
    {
        printf("Straight flush");
    }
    else if (four)
    {
        printf("Four of a kind");
    }
    else if (three && pairs == 1)
    {
        printf("Full house");
    }
    else if (flush)
    {
        printf("Flush");
    }
    else if (straight)
    {
        printf("Straight");
    }
    else if (three)
    {
        printf("Three of a kind");
    }
    else if (pairs == 2)
    {
        printf("Two pairs");
    }
    else if (pairs == 1)
    {
        printf("Pair");
    }
    else
    {
        printf("High card");
    }

    printf("\n\n");
}