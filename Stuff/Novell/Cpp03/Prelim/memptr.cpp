#include <iostream>
using namespace std;

class C
{
public:
    void f() {cout << "C::f\n";}
    void g() {cout << "C::g\n";}
};

int main()
{
    C c;
    
    // Using an object
    void (C::*pmf)() = &C::f;
    (c.*pmf)();
    pmf = &C::g;
    (c.*pmf)();
    
    // Using pointer to an object
    C* cp = &c;
    pmf = &C::f;
    (cp->*pmf)();
    pmf = &C::g;
    (cp->*pmf)();
}

