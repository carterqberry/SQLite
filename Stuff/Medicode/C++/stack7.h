// stack7.h: The StackOfInt class with Exceptions

#ifndef STACK7_H
#define STACK7_H

#include <iosfwd>
#include <new>
#include <stdexcept>
#include <string>

class StackError : public std::logic_error
{
public:
    StackError(const std::string& s)
        : std::logic_error(s)
    {}
};

class StackOfInt
{
public:
    StackOfInt(int) throw(StackError, std::bad_alloc);
    ~StackOfInt();

    void push(int);
    int pop() throw(StackError);
    int top() const throw(StackError);
    int size() const;

    int operator[](int idx) const throw (StackError);
    int& operator[](int idx) throw (StackError);

    friend std::ostream& operator<<(std::ostream&,
                                    const StackOfInt&);

private:
    enum {CHUNK = 10};
    int* data;
    int max;
    int ptr;
};

inline StackOfInt::~StackOfInt()
{
    delete [] data;
    max = ptr = 0;
}

inline int StackOfInt::size() const
{
    return ptr;
}

#endif

