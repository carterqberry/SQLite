#include <iostream>
using namespace std;

struct BaseExcept {BaseExcept() {cout << "BaseExcept\n";}};

struct DerivedExcept : BaseExcept {DerivedExcept() {cout << "DerivedExcept\n";}};

struct RogueExcept {RogueExcept() {cout << "RogueExcept\n";}};

class Base
{
public:
   virtual void f() throw(BaseExcept) {throw BaseExcept();}
};

class Derived : public Base
{
public:
    // Any of these three is okay:
//   void f() throw(BaseExcept) {throw BaseExcept();}
//   void f() throw(DerivedExcept) {throw DerivedExcept();}
//   void f() throw() {}

    // This would be an error (caught at compiler time):
//   void f() {}
};

int main()
{
   Derived d;
   try
   {
      d.f();
   }
   catch(...)
   {}
}

