// Illustrates the limits of class conversions
#include <iostream>
using namespace std;

class A
{
   int x;
public:
   explicit A(int x)    // Note "explicit" keyword
   {
      this->x = x;
      cout << "Creating an A from the int " << x << endl;
   }
   int getX() const
   {
      return x;
   }
};

class B
{
   A myA;
public:
   B(const A& a) : myA(a)
   {
      cout << "Creating a B from an A(" << a.getX() << ")\n";
   }
   A getA() const
   {
      return myA;
   }
};

int main()
{
   // B b(1);  // Error! 
   B b(A(1));  // OK
}

