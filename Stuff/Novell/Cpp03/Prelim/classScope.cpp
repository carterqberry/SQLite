#include <iostream>
using namespace std;

class Base
{
public:
   static int b;
   void f() {};
};

int Base::b = 1;

class Derived : public Base
{
public:
   enum {d = 2};
   void f(int) {};
};

int main()
{
   cout << Base::b << endl;      // 1
   cout << Derived::d << endl;   // 2
   Derived d;
   d.f(1);     // okay
   d.f();      // error!
}

/*
Borland C++ 5.5.1 for Win32 Copyright (c) 1993, 2000 Borland
c:\uvsc\spring02\3370\classscope.cpp:
Error E2193 c:\uvsc\spring02\3370\classscope.cpp 20: Too few parameters in call to 'Derived::f(int)' in function main()
*** 1 errors in Compile ***
*/
