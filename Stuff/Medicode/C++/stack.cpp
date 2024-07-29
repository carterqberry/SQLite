// stack7.cpp
#include "stack7.h"
#include <iostream>
#include <cassert>
using namespace std;

StackOfInt::StackOfInt(int siz)
{
    assert(siz > 0);
    data = new int[siz];
    max = siz;
    ptr = 0;
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

int StackOfInt::pop()
{
    assert(ptr > 0);
    return data[--ptr];
}

int StackOfInt::top() const
{
    assert(ptr > 0);
    return data[ptr - 1];
}

