#include <iostream>

class Base
{
public:
   void f(){}
};

class Derived : public Base
{
   void f(){}
};

int main()
{
   Derived d;
   d.f();     // Line 17: Access error!
}

/* Output:
Borland C++ 5.5 for Win32 Copyright (c) 1993, 2000 Borland
Lookup2.cpp:
Error E2247 Lookup2.cpp 17: 'Derived::f()' is not accessible in function main()
*** 1 errors in Compile ***
*/

