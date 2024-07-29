#include <iostream>
using namespace std;

class T
{
   int x;
public:
   T(int x)
   {
      this->x = x;
   }
   operator bool() const
   {
      cout << "Executing operator bool\n";
      return x != 0;
   }
};

int main()
{
   T t0(0);
   T t1(1);

   if (t0)
      cout << "t0 tests true\n";
   else
      cout << "t0 tests false\n";

   if (t1)
      cout << "t1 tests true\n";
   else
      cout << "t1 tests false\n";
}

/* Output:
Executing operator bool
t0 tests false
Executing operator bool
t1 tests true
*/

