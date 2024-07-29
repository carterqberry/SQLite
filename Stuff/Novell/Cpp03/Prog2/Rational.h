// Rational.h: Definition of the Rational class
// Program 1: CNS 1350 (Section 003)
// Author: Chuck Allison
#ifndef RATIONAL_H
#define RATIONAL_H

#include <cassert>
#include <iosfwd>

using std::istream;
using std::ostream;

class Rational
{
public:
   Rational(int numerator = 0, int denominator = 1);

   // Arithmetic
   Rational& operator++();    // (extra credit)
   Rational operator++(int);  // (extra credit)
   Rational& operator--();    // (extra credit)
   Rational operator--(int);  // (extra credit)

   // Stream operators
   friend ostream& operator<<(ostream&, const Rational&);
   friend istream& operator>>(istream&, Rational&);

   // Assignment
   Rational& operator+=(const Rational&);
   Rational& operator-=(const Rational&);
   Rational& operator*=(const Rational&);
   Rational& operator/=(const Rational&);

   // Another helper (public, to reduce friendship)
   int compare(const Rational&) const;
private:
   // Data
   int numerator;
   int denominator;

   // Convenient helper functions
   void reduce();
   static int gcd(int, int);
};

inline Rational::Rational(int numerator, int denominator)
{
   this->numerator = numerator;
   this->denominator = denominator;
   reduce();
}

// Arithmetic
inline Rational operator+(Rational r1, const Rational& r2)
{
   return r1 += r2;
}
inline Rational operator-(Rational r1, const Rational& r2)
{
   return r1 -= r2;
}
inline Rational operator*(Rational r1, const Rational& r2)
{
   return r1 *= r2;
}
inline Rational operator/(Rational r1, const Rational& r2)
{
   return r1 /= r2;
}

// Relationals
inline bool operator<(const Rational& r1, const Rational& r2)
{
   return r1.compare(r2) < 0;
}
inline bool operator>(const Rational& r1, const Rational& r2)
{
   return r1.compare(r2) > 0;
}
inline bool operator<=(const Rational& r1, const Rational& r2)
{
   return r1.compare(r2) <= 0;
}
inline bool operator>=(const Rational& r1, const Rational& r2)
{
   return r1.compare(r2) >= 0;
}
inline bool operator==(const Rational& r1, const Rational& r2)
{
   return r1.compare(r2) == 0;
}
inline bool operator!=(const Rational& r1, const Rational& r2)
{
   return !operator==(r1, r2);
}
inline int Rational::compare(const Rational& r2) const
{
   //?
}

// Increment/decrement
inline Rational& Rational::operator++()
{
   //?
}
inline Rational Rational::operator++(int)
{
   //?
}
inline Rational& Rational::operator--()
{
   //?
}
inline Rational Rational::operator--(int)
{
   //?
}

// Assignment
inline Rational& Rational::operator+=(const Rational& r)
{
   //?
}
inline Rational& Rational::operator-=(const Rational& r)
{
   //?
}
inline Rational& Rational::operator*=(const Rational& r)
{
   //?
}
inline Rational& Rational::operator/=(const Rational& r)
{
   //?
}
#endif

