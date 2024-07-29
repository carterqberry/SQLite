/* deal.c:  Deal a hand from a shuffled deck of cards -
 *
 *		Illustrates the following functions:
 *
 *		From stdlib.h:
 *			abs, atoi, div, rand, and srand
 *
 *		From string.h:
 *			memchr
 *
 *		From time.h:
 *			time
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DECKSIZE 52
#define SUITSIZE 13

int main(int argc, char *argv[])
{
    int ncards = DECKSIZE;   /* Deal full deck by default */
    char deck[DECKSIZE];     /* An array of small integers */
    size_t deckp;
		unsigned int seed;

    /* Get optional hand size */
    if (argc > 1)
        if ((ncards = abs(atoi(argv[1])) % DECKSIZE) == 0)
            ncards = DECKSIZE;

		/* Seed the random number generator */
		seed = (unsigned int) time(NULL);
		srand(seed);

		/* Shuffle */
    deckp = 0;
    while (deckp < ncards)
    {
        int num = rand() % DECKSIZE;
        if (memchr(deck, num, deckp) == NULL)
            deck[deckp++] = (char) num;
    }

    /* Deal */
    for (deckp = 0; deckp < ncards; ++deckp)
    {
        div_t card = div(deck[deckp], SUITSIZE);
        printf("%c(%c)%c",
               "A23456789TJQK"[card.rem],
               "CDHS"[card.quot],
               (deckp+1) % SUITSIZE ? ' ' : '\n');
    }

    return 0;
}
