// stack5.h: The StackOfInt class from Chapter 5

#ifndef STACK5_H
#define STACK5_H

#include <assert.h>
#include <iosfwd>
using std::ostream;

class StackOfInt
{
public:
    StackOfInt(int);
    ~StackOfInt();

    void push(int);
    int pop();
    int top() const;
    int size() const;

    int operator[](int idx) const;
    int& operator[](int idx);

    friend ostream& operator<<(ostream&, const StackOfInt&);

private:
    int* data;
    int max;
    int ptr;
};

inline StackOfInt::StackOfInt(int siz)
{
    assert(siz > 0);
    data = new int[siz];
    max = siz;
    ptr = 0;
}

inline StackOfInt::~StackOfInt()
{
    delete [] data;
    max = ptr = 0;
}

inline void StackOfInt::push(int x)
{
    assert(ptr < max);
    data[ptr++] = x;
}

inline int StackOfInt::pop()
{
    assert(ptr > 0);
    return data[--ptr];
}

inline int StackOfInt::top() const
{
    assert(ptr > 0);
    return data[ptr - 1];
}

inline int StackOfInt::size() const
{
    return ptr;
}

inline int StackOfInt::operator[](int idx) const
{
    assert(0 <= idx && idx < ptr);
    return data[idx];
}

inline int& StackOfInt::operator[](int idx)
{
    assert(0 <= idx && idx < ptr);
    return data[idx];
}

#endif

