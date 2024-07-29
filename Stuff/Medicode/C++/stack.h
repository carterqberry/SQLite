#include <iosfwd>
#include <new>
#include <string>

class StackOfInt
{
public:
    StackOfInt(int);
    ~StackOfInt();

    void push(int);
    int pop();
    int top();
    int size() const;

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

