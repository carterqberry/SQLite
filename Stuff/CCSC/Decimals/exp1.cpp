// Computes e^x via Taylor's Series (using partial sums)
// The problem with negative exponents is that the natural
// roundoff error in leading terms (which are large) is
// larger than the final result, so all precision is lost
// early on.
#include <cfloat>
#include <cmath>
#include <iostream>
using namespace std;

template<typename FType>
FType myexp(FType x) {
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
   return sum2;
}

void display(const char* label, float value) {
   cout.precision(FLT_DIG-1);
   cout << label << value << endl;
}

void display(const char* label, double value) {
   cout.precision(DBL_DIG-1);
   cout << label << value << endl;
}

int main() {
   // Compare myexp to library
   cout.setf(ios::showpoint);
   cout.setf(ios::scientific);
   display("myexp(55.5f) = ", myexp(55.5f));
   display("myexp(55.5) = ", myexp(55.5));
   display("exp(55.5) = ", exp(55.5));
   display("myexp(-55.5f) = ", myexp(-55.5f));
   display("myexp(-55.5) = ", myexp(-55.5));
   display("exp(-55.5) = ", exp(-55.5));
}

/* Output:
myexp(55.5f) = 1.26866e+24
myexp(55.5) = 1.26865561401096e+24
exp(55.5) = 1.26865561401096e+24
myexp(-55.5f) = -2.90487e+15
myexp(-55.5) = -6.76350603787201e+06
exp(-55.5) = 7.88235979060085e-25
*/
