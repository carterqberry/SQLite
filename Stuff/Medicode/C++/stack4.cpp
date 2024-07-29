// stack4.cpp
#include "stack4.h"
#include <iostream>
using namespace std;

ostream& operator<<(ostream& os, const StackOfInt& stk)
{
    os << '{';
    for (int i = 0; i < stk.ptr; ++i)
    {
        if (i > 0)
            os << ',';
        os << stk.data[i];
    }
    os << '}';
    return os;
}
