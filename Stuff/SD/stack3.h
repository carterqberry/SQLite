// stack2.h
#include <cassert>
#include <cstddef>
#include <stdexcept>
#include <string>
#include <new>

using std::size_t;
using std::logic_error;
using std::string;
using std::bad_alloc;
using std::bad_exception;

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
    Stack(size_t) throw(StackError, bad_alloc, bad_exception);
    ~Stack();

    void push(const T&) throw(bad_alloc, bad_exception);
    T pop() throw(StackError, bad_exception);
    T top() const throw(StackError, bad_exception);
    size_t size() const;

private:
    enum {CHUNK = 10};
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
void Stack<T>::push(const T& x) throw(bad_alloc)
{
    using namespace std;
    if (ptr == max)
    {
        // Grow the array:
        size_t new_max = max + CHUNK;
        T* new_data = new T[new_max];
        for (size_t i = 0; i < ptr; ++i)
            new_data[i] = data[i];
        delete [] data;
        data = new_data;
        max = new_max;
    }

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

