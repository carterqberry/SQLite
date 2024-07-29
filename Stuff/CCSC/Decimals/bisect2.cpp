// bisect2.cpp: Computes a zero by the bisection method.
// This version tames the tolerance.

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <limits>
using namespace std;

// "tol" here repesents absolute error (not relative)
double bisect(double tol, double a, double b, double f(double)) {
   assert(b > a);
   double eps = numeric_limits<double>::epsilon();
   tol = max(tol, eps*fabs(a));
   tol = max(tol, eps*fabs(b));
   while (b-a >= 2*tol) {
      assert(f(a)*f(b) < 0);
      double c = (a+b)/2.0;
      if (f(a)*f(c) < 0)
         b = c;
      else if (f(b)*f(c) < 0)
         a = c;
      else
         return c;
   }
   return (a + b) / 2.0;
}

// A function whose root we wish to find in some range
double f(double x) {
   return x*cos(x) + sin(x);
}

int main() {
   cout.precision(numeric_limits<double>::digits10 - 1);
   double root = bisect(.0005, 1.5, 2.5, f);
   cout << root << ", " << f(root) << endl;
   root = bisect(.00000005, 1.5, 2.5, f);
   cout << root << ", " << f(root) << endl;
}
