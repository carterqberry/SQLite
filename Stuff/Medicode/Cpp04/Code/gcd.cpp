// gcd.cpp: A recursive algorithm for the greatest common divisor of two integers
#include <iostream>
using namespace std;

int gcd(int x, int y)
{
   return (y == 0) ? x : gcd(y, x%y);
}

int main()
{
   cout << "gcd(10, 7) == " << gcd(10, 7) << endl;
   cout << "gcd(10, 5) == " << gcd(10, 5) << endl;
   cout << "gcd(5, 10) == " << gcd(5, 10) << endl;
   cout << "gcd(10, 10) == " << gcd(10, 10) << endl;
}

