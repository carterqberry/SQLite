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
   operator const void*() const
   {
      cout << "Executing operator void*\n";
      return x ? static_cast<const void*>(this) : 0;
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

