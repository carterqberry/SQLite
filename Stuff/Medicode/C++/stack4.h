// stack4.h: The StackOfInt class from Chapter 4

#ifndef STACK4_H
#define STACK4_H

#include <assert.h>
#include <iosfwd>
using std::ostream;

class StackOfInt
{
public:
    StackOfInt();

    void push(int);
    int pop();
    int top() const;
    int size() const;

    int operator[](int idx) const;
    int& operator[](int idx);

    friend ostream& operator<<(ostream&, const StackOfInt&);

private:
    enum {MAX = 100};
    int data[MAX];
    int ptr;
};

inline StackOfInt::StackOfInt()
{
    ptr = 0;
}
    
inline void StackOfInt::push(int x)
{
    assert(ptr < MAX);
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

