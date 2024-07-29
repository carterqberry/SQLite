// cursed.cpp
#include <iostream>
#include <cassert>
using namespace std;

// Shows when NOT to use recursion:
int sum1(int n)
{
   assert(n >= 0);
   return (n == 0) ? 0 : n + sum1(n-1);
}

// Iterate when you can:
int sum2(int n)
{
   assert(n >= 0);
   int sum = n;
   while (--n)
      sum += n;
   return sum;
}

int main()
{
   cout << sum1(10) << endl;
   cout << sum2(10) << endl;
}

