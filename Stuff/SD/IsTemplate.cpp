// IsTemplate.cpp {-bor}
#include <iostream>
#include <vector>
using namespace std;

template<typename T>
struct IsTemplate {
   enum { numargs = 0 };
};

template<template<typename> class X, typename T>
struct IsTemplate< X<T> > {
   enum { numargs = 1 };
   typedef T type;   // extract T!
};

template<template<typename, typename> class X, typename T1, typename T2>
struct IsTemplate< X<T1, T2> > {
   enum { numargs = 2 };
   typedef T1 type1;
   typedef T2 type2;
};

// A test template
template<typename T>
struct Foo {
   T t;
};

int main() {
   typedef IsTemplate<int> Int;
   if (Int::numargs == 0)
      cout << "Int is not a template\n";

   typedef IsTemplate< Foo<double> > Foo_t;
   if (Foo_t::numargs) {
      cout << "Foo_t is a template with " << Foo_t::numargs << " argument(s)\n";
      cout << "Its argument has size " << sizeof(Foo_t::type) << endl;
   }

   typedef IsTemplate< vector<int> > IntVec;
   if (IntVec::numargs) {
      cout << "IntVec is a template with " << IntVec::numargs << " argument(s)\n";
      cout << "Its first argument has size " << sizeof(IntVec::type1) << endl;
      cout << "Its second argument has size " << sizeof(IntVec::type2) << endl;
   }
}

/* Output:
Int is not a template
Foo_t is a template with 1 argument(s)
Its argument has size 8
IntVec is a template with 2 argument(s)
Its first argument has size 4
Its second argument has size 1
*/

