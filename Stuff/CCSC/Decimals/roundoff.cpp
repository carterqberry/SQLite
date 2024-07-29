#include <iostream>
#include <limits>
using namespace std;

int main() {
   float x = 1.0f - .2f -.2f -.2f -.2f -.2f;
   cout << x << endl;
   
   cout.precision(numeric_limits<double>::digits10);
   double y = 1.0 - .2 -.2 -.2 -.2 -.2;
   cout << y << endl;
}

/*
-1.49012e-08
-5.55111512312578e-17
*/
