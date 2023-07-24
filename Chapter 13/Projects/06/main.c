/*
Improve the planet.c program of Section 13.7 by having it ignore case when comparing
command-line arguments with strings in the planets array.
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_PLANETS 9

int main(int argc, char *argv[])
{
  char *planets[] = {"Mercury", "Venus", "Earth",
                     "Mars", "Jupiter", "Saturn",
                     "Uranus", "Neptune", "Pluto"};
  int i, j;
  char *a, *p;
  int argument_length;

  for (i = 1; i < argc; i++)
  {
    for (j = 0; j < NUM_PLANETS; j++)
    {
        argument_length = strlen(argv[i]);

        if (argument_length != strlen(planets[j]))
        {
            continue;
        }

        a = argv[i];
        p = planets[j];

        for (int k = 0; k < argument_length; k++)
        {
            if (tolower(*p) != tolower(*a))
            {
                break;
            }
        }

        if (*p == *a)
        {
            printf("%s is planet %d\n", argv[i], j + 1);
            break;
        }        
    }

    if (j == NUM_PLANETS)
    {
        printf("%s is not a planet\n", argv[i]);
    }
  }

  exit(EXIT_SUCCESS);
}