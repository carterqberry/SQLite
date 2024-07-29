// Computes e^x via Taylor's Series (using partial sums)
// This version corrects the problem with negative
// exponents by using the reciprocal.
#include <cmath>
#include <iostream>
using namespace std;

template<typename FType>
FType myexp(FType x) {
   bool negative = false;
   if (x < 0) {
      negative = true;
      x = -x;
   }

   FType sum1 = 1;
   FType sum2 = 1 + x;
   FType term = x;
   int i = 1;
   while (sum2 != sum1) {
      sum1 = sum2;
      ++i;
      term = term*x/i;
      sum2 += term;
   }
   cout << "(" << i << "terms) ";
   return negative ? 1/sum2 : sum2;
}

int main() {
   // Compare myexp to library
   cout << "myexp(55.5f) = " << myexp(55.5f) << endl;
   cout << "myexp(55.5) = " << myexp(55.5) << endl;
   cout << "exp(55.5) = " << exp(55.5) << endl;
   cout << "myexp(-55.5f) = " << myexp(-55.5f) << endl;
   cout << "myexp(-55.5) = " << myexp(-55.5) << endl;
   cout << "exp(-55.5) = " << exp(-55.5) << endl;
}

/* Output:

myexp(55.5f) = 1.26866e+24
myexp(55.5) = 1.26866e+24
exp(55.5) = 1.26866e+24
myexp(-55.5f) = 7.88236e-25
myexp(-55.5) = 7.88236e-25
exp(-55.5) = 7.88236e-25
*/
