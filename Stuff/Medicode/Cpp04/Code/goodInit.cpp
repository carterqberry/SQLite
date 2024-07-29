#include <iostream>
using namespace std;

class Member
{
   int x;
public:
   Member()
   {
      cout << "Default ctor\n";
      x = 0;
   }
   Member(int x)
   {
      cout << "Single-arg int ctor\n";
      this->x = x;
   }
   void setX(int x)
   {
      cout << "Setting Member::x\n";
      this->x = x;
   }
};

class Wrapper
{
   Member mem;
public:
   Wrapper(int n) : mem(n)
   {
      cout << "Initializing mem\n";
//      mem.setX(n);
   }
};

int main()
{
   Wrapper w(3);
}

