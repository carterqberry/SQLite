// convert.cpp: Illustrates a Conversion Sequence
#include <iostream>
using namespace std;

class A
{
   float x;
public:
   A(float x)
   {
      this->x = x;
      cout.setf(ios::showpoint);
      cout << "Creating an A from the float " << x << endl;
   }
};

int main()
{
   A a(1);
}

/* Output:
Creating an A from the float 1.00000
*/
