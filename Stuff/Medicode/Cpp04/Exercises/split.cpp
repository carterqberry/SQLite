#include <iostream>
using namespace std;

long split(double val, double& frac) {
   long integer = long(val);
   frac = val - integer;
   return integer;
}

int main() {
   double frac;
   long integer = split(5.67,frac);
   cout << " 5.67 = " << integer << " + " << frac << endl;
}
