// bisect.cpp: Computes a zero by the bisection method.

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <stdexcept>
#include "ieee2.h"
#include "ulps.h"
using namespace std;

void bisect(double& a, double& b, double f(double)) {
   if (a >= b || sign(f(a)) == sign(f(b)))
      throw logic_error("Bad interval");

   // Bisect until zero found or interval is 1 ulp
   int nevals = 0;
   for (;;) {
      // Loop invariants
      assert(b > a);
      double fa = f(a);
      ++nevals;
      int sign_a = sign(fa);
      assert(sign_a != sign(f(b)));

      double c = (a+b)/2.0;

      // At 1 ulp?
      if (c <= a || c >= b)
         break;

      double fc = f(c);
      ++nevals;
      if (fc == 0.0) {
         // Stumbled across a zero.
         a = c;
         b = c;
         break;
      }
      else if (sign_a == sign(fc))
         a = c;
      else {
         assert(sign(f(b)) == sign(f(c)));
         b = c;
      }
   }
   cout << "nevals = " << nevals << endl;
}

// A function whose root we wish to find in some range
double f(double x) {
   return x*cos(x) + sin(x);
}

int main() {
   cout.precision(numeric_limits<double>::digits10 + 1);
   double a = 1.5, b = 2.5;
   bisect(a, b, f);
   cout << '[' << a << ',' << b << "] (" << ulps(a,b) << " ulp)\n";
}

/* Output:
nevals = 103
[2.028757838110434,2.028757838110435] (1 ulp)
*/
