// Illustrates the limits of class conversions
#include <iostream>
using namespace std;

class A
{
   int x;
public:
   A(int x)
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

class C
{
   B myB;
public:
   C(const B& b) : myB(b)
   {
      cout << "Creating a C from a B(A(" << b.getA().getX() << "))\n";
   }
};

int main()
{
   B b(1);
   cout << endl;
   C c(A(2));
   cout << endl;
   // C c2(2); // Error!
}

/* Output:
Creating an A from the int 1
Creating a B from an A(1)

Creating an A from the int 2
Creating a B from an A(2)
Creating a C from a B(A(2))

*/
