#include <iostream>

class Base
{
public:
   void f(int){}
};

class Derived : public Base
{
   void f(){}
};

int main()
{
   Derived d;
   d.f(123);     // Line 17: Overload error!

   Base* p = &d;
   p->f(123);    // okay, looks in scope of Base
}

/* Output: (A bug in Borland)
Borland C++ 5.5 for Win32 Copyright (c) 1993, 2000 Borland
Lookup3.cpp:
Error E2247 Lookup3.cpp 17: 'Derived::f()' is not accessible in function main() <wrong>
*** 1 errors in Compile ***
*/

