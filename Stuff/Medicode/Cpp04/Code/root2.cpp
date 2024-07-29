// root.cpp: Passsing a function as a parameter (C89 syntax)
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cassert>
using namespace std;

double root(double start, double end, double g(double))  // difference here
{
   double startVal = g(start);
   double endVal = g(end);
   assert(g(start) * g(end) < 0);

   while (fabs(end - start) > fabs(DBL_EPSILON*start))
   {
      double midpt = (start + end) / 2.0;
      double midVal = g(midpt);
      if (startVal*midVal < 0)
         end = midpt;
      else if (endVal*midVal < 0)
         start = midpt;
      else
         break;   // Very unlikely
   }
   return start;  // or end, doesn't matter!
}

double f(double x)
{
   return x * x - 2.0;
}

int main(int argc, char* argv[])
{
   if (argc >= 3)
   {
      double start = atof(argv[1]);
      double end = atof(argv[2]);
      cout << "root = " << root(start, end, f) << endl;
   }
}

