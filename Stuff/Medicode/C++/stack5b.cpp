// stack5b.cpp
#include "stack5b.h"
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

void StackOfInt::push(int x)
{
    if (ptr == max)
    {
        // Grow the array:
        int new_max = max + CHUNK;
        cout << "Growing array to " << new_max << " ...\n";
        int* new_data = new int[new_max];
        for (int i = 0; i < ptr; ++i)
            new_data[i] = data[i];
        delete [] data;
        data = new_data;
        max = new_max;
    }

    assert(ptr < max);
    data[ptr++] = x;
}

