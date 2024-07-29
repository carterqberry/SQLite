#include <iostream>
using namespace std;

// A Primary Template
template<class T>
class Foo {
public:
    void f();	// member function decls…
    void g();
};

template<class T>	// member function defs…
void Foo<T>::f() {
    cout << "f using primary template\n";
}

template<class T>
void Foo<T>::g() {
    cout << "g using primary template\n";
}
// A Full Specialization
template<>
class Foo<int> {
public:
    void f();
    void g();
};
/*
// NOTE: No template keyword here
void Foo<int>::f();
void Foo<int>::g();
*/
