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
  char *k, *l;

  for (i = 1; i < argc; i++)
  {
    for (j = 0; j < NUM_PLANETS; j++)
    {
        if (strlen(argv[i]) != strlen(planets[j]))
        {
            continue;
        }

        k = argv[i];
        l = planets[j];

        for (k = argv[i], l = planets[j]; *k != '\n'; k++, l++)
        {
            if (tolower(*k) != tolower(*l))
            {
                break;
            }
        }

        if (tolower(*k) != tolower(*l))
        {
            break;
        }

        printf("%s is planet %d\n", argv[i], j + 1);
        break;
        
    }

    if (j == NUM_PLANETS)
    {
        printf("%s is not a planet\n", argv[i]);
    }
  }

  exit(EXIT_SUCCESS);
}