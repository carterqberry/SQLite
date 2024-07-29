#include <iostream>

class Base
{
public:
   void f(int){}
};

class Derived : public Base
{
public:
   void f(double, int){}
};

int main()
{
   int i;
   Derived d;
   d.f(i);     // error!
}

/* Output:
Borland C++ 5.5 for Win32 Copyright (c) 1993, 2000 Borland
Hide.cpp:
Error E2193 Hide.cpp 19: Too few parameters in call to 'Derived::f(double,int)' in function main()
*** 1 errors in Compile ***
*/

