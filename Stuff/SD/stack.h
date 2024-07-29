// stack.h
#include <cassert>
#include <cstddef>
using std::size_t;

template<typename T>
class Stack
{
public:
    Stack(size_t);
    ~Stack();

    void push(const T&);
    T pop();
    T top() const;
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
Stack<T>::Stack(size_t siz)
{
    using namespace std;
    assert(siz > 0);
    data = new T[siz];
    max = siz;
    ptr = 0;
}

template<typename T>
void Stack<T>::push(const T& x)
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
T Stack<T>::pop()
{
    using namespace std;
    assert(ptr > 0);
    return data[--ptr];
}

template<typename T>
T Stack<T>::top() const
{
    using namespace std;
    assert(ptr > 0);
    return data[ptr - 1];
}

