#include "foo.h"

// NOTE: No template keyword here
void Foo<int>::f() {
    cout << "f using int specialization\n";
}

void Foo<int>::g() {
    cout << "g using int specialization\n";
}

