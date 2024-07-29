// stack.h
#include <cassert>
#include <cstddef>
#include <stdexcept>
#include <string>
#include <new>

using std::logic_error;
using std::string;
using std::bad_alloc;
using std::size_t;

class StackError : public logic_error
{
public:
    StackError(const string& s)
        : logic_error(s)
    {}
};

template<typename T>
class Stack
{
public:
    Stack(size_t) throw(StackError, bad_alloc);
    ~Stack();

    void push(const T&) throw(StackError);
    T pop() throw(StackError);
    T top() const throw(StackError);
    size_t size() const;
    void clear();

private:
    T* data;
    size_t max;
    size_t ptr;
};

template<typename T>
inline Stack<T>::~Stack()
{
    delete [] data;
    max = ptr = 0;
}

template<typename T>
inline size_t Stack<T>::size() const
{
    return ptr;
}

template<typename T>
Stack<T>::Stack(size_t siz) throw(StackError, bad_alloc)
{
    if (siz == 0)
        throw StackError("bad size in Stack(size_t)");
    data = new T[siz];
    max = siz;
    ptr = 0;
}

template<typename T>
void Stack<T>::push(const T& x) throw(StackError)
{
    if (ptr == max)
        throw StackError("stack overflow");

    assert(ptr < max);
    data[ptr++] = x;
}

template<typename T>
T Stack<T>::pop() throw(StackError)
{
    if (ptr == 0)
        throw StackError("stack underflow");
    return data[--ptr];
}

template<typename T>
T Stack<T>::top() const throw(StackError)
{
    if (ptr == 0)
        throw StackError("stack underflow");
    return data[ptr - 1];
}

template<typename T>
void Stack<T>::clear()
{
   ptr = 0;
}
