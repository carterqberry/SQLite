// stack7.cpp
#include "stack7.h"
#include <iostream>
#include <cassert>
using namespace std;

StackOfInt::StackOfInt(int siz) throw(StackError, bad_alloc)
{
    if (siz <= 0)
        throw StackError("bad stack size in constructor");
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

int StackOfInt::pop() throw (StackError)
{
    if (ptr <= 0)
        throw StackError("underflow");
    return data[--ptr];
}

int StackOfInt::top() const throw(StackError)
{
    if (ptr <= 0)
        throw StackError("underflow");
    return data[ptr - 1];
}

int StackOfInt::operator[](int idx) const throw(StackError)
{
    if (idx < 0 || ptr <= idx)
        throw StackError("index out of range");
    return data[idx];
}

int& StackOfInt::operator[](int idx) throw(StackError)
{
    if (idx < 0 || ptr <= idx)
        throw StackError("index out of range");
    return data[idx];
}

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

