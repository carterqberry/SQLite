#include <iostream>
#include <string>
using namespace std;

template<class T>
void f(const T&);

template<class U>
class Foo {
    U u;
public:
    Foo(const U& parm) : u(parm) {}
    U get() const { return u; }
    template <class T>
    friend void f(const Foo<U>& u, const T& t) {
        cout << "u: " << u.get() << endl;
        cout << "T: " << typeid(t).name() << endl;
    }
};

template<class U>
U Foo<U>::u;

int main() {
    Foo<int> x;
    f(x);       // Foo<int>
    f(1.0);     // double
    Foo<string> s;
    f(s);
//    f(string("hello"));     // double
}
