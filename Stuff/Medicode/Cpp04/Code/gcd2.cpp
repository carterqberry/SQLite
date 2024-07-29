// gcd2.cpp: An iterative version of gcd
#include <iostream>
using namespace std;

int gcd(int x, int y)
{
   while (y != 0)
   {
      int rem = x % y;
      x = y;
      y = rem;
   }
   return x;
}

int main()
{
   cout << "gcd(10, 7) == " << gcd(10, 7) << endl;
   cout << "gcd(10, 5) == " << gcd(10, 5) << endl;
   cout << "gcd(5, 10) == " << gcd(5, 10) << endl;
   cout << "gcd(10, 10) == " << gcd(10, 10) << endl;
}

