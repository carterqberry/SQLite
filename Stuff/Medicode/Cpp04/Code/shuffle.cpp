// deal.cpp: Deal a hand from a shuffled deck of cards
#include <iostream>
#include <cstdlib>   // srand, rand, div
#include <cstring>   // memchr
#include <ctime>     // time
#include <string>    // string class

int main()
{
   using namespace std;
   const int DECKSIZE = 52;
   const int SUITSIZE = 13;
   int ncards = DECKSIZE;  // Deal full deck by default

   // Seed the random number generator
   unsigned int seed = time(0);
   srand(seed);

   // Shuffle
   int deckp = 0;          // Keeps track of how many cards dealt
   char deck[DECKSIZE];    // The cards (byte-size integers)
   while (deckp < ncards)
   {
      int num = rand() % DECKSIZE;
      if (memchr(deck, num, deckp) == 0)
         deck[deckp++] = char(num);
   }

   // Deal
   string denom("A23456789TJQK");
   string suit("CDHS");
   for (deckp = 0; deckp < ncards; ++deckp)
   {
       div_t card = div(deck[deckp], SUITSIZE);
       cout << denom[card.rem]
            << '(' << suit[card.quot] << ") "
            << ((deckp+1) % SUITSIZE ? ' ' : '\n');
   }
   cin.get();
}

/* Output:
4(C)  6(S)  J(D)  Q(D)  7(H)  5(D)  5(C)  8(S)  8(C)  J(S)  6(D)  5(S)  K(H) 
9(C)  9(S)  2(C)  7(C)  7(D)  T(S)  T(H)  6(C)  2(S)  Q(H)  A(S)  Q(C)  9(H) 
4(H)  2(H)  Q(S)  K(C)  3(C)  3(S)  T(D)  J(H)  K(S)  3(H)  A(D)  K(D)  A(H) 
T(C)  9(D)  6(H)  8(H)  7(S)  4(S)  4(D)  5(H)  2(D)  8(D)  3(D)  A(C)  J(C) 
*/

