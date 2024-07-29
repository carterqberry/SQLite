#include <iostream>
#include "StackTest.h"
using namespace std;

int main()
{
    StackTest t;
    t.setStream(&cout);
    t.run();
    t.report();
}

