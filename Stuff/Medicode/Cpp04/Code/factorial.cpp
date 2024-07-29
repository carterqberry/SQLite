// factorial.cpp
#include <iostream>
#include <cassert>
using namespace std;

// Still not a good idea:
int fact1(int n)
{
   assert(n >= 0);
   return (n <= 1) ? 1 : n * fact1(n-1);
}

// Iterate when you can:
int fact2(int n)
{
   assert(n >= 0);
   int prod = n;
   while (--n > 1)
      prod *= n;
   return prod;
}

int main()
{
   cout << fact1(10) << endl;
   cout << fact2(10) << endl;
}

