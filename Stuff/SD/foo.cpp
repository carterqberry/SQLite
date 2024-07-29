#include "foo.h"

int main() {
    Foo<char> c;
    Foo<int> i;
    c.f();
    c.g();
    i.f();
    i.g();
}

