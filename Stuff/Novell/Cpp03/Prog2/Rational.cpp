// Rational.cpp: Implementation for the Rational class
// Author: Chuck Allison
#include "Rational.h"
#include <iostream>
#include <cstdlib>
using namespace std;

int Rational::gcd(int x, int y)
{
   while (y != 0)
   {
      int rem = x % y;
      x = y;
      y = rem;
   }
   return abs(x);
}

void Rational::reduce()
{
   //?
}

istream& operator>>(istream& is, Rational& r)
{
   int num, den;
   char slash;
   is >> num >> slash;
   if (slash != '/')
      is.setstate(ios::failbit);
   is >> den;
   if (den == 0)
      is.setstate(ios::failbit);
   if (is)
   {
      // Only change r if no input errors
      r.numerator = num;
      r.denominator = den;
      r.reduce();
   }
   return is;
}

ostream& operator<<(ostream& os, const Rational& r)
{
   //?
}

