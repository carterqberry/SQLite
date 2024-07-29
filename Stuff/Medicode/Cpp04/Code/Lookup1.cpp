#include <iostream>

class A;

class B
{
public:
   void f(A*){}
private:
   void f(B*){}
};

int main()
{
   B b;
   A* p;

   b.f(p);  // Okay: calls B::f(A*);
   b.f(0);  // Line 19: Overload error
   b.f(&b); // Line 20: Access error
}

/* Output:
Borland C++ 5.5 for Win32 Copyright (c) 1993, 2000 Borland
Lookup1.cpp:
Error E2015 Lookup1.cpp 19: Ambiguity between 'B::f(A *)' and 'B::f(B *)' in function main()
Error E2247 Lookup1.cpp 20: 'B::f(B *)' is not accessible in function main()
*** 2 errors in Compile ***
*/

