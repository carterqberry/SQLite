// Vector.h
#include <iostream>
#include <cstdlib>
#include <new>

using std::size_t;   // bombs in MS VC++

// The next two functions are just for tracing execution:
inline void *operator new(size_t siz)
{
    using namespace std;
    printf(">>> operator new (%u bytes)\n", siz);
    return malloc(siz);
}

inline void operator delete(void *p)
{
    using namespace std;
    printf(">>> operator delete: %p\n", p);
    free(p);
}

template<class T>
class Vector
{
public:
    Vector();
    Vector(size_t);
    ~Vector();

    // Append & subscript:
    Vector<T>& operator+=(const T&);
    T& operator[](size_t);

    // Length-related functions:
    size_t length() const;
    void resize(size_t);
    size_t capacity() const;
    void reserve(size_t);

private:
    T *arena;		// class-specific storage arena
    size_t length_;
    size_t capacity_;

    enum {CHUNK = 10};

    // Disallow copy and assign:
    Vector(const Vector&);
    Vector<T>& operator=(const Vector<T>&);

    static size_t next_chunk(size_t n);
};

template<class T>
inline Vector<T>::Vector()
{
    // Intialize an empty vector
    arena = 0;
    length_ = capacity_ = 0;
}

template<class T>
inline Vector<T>::Vector(size_t n)
{
    // Allocate a multiple of CHUNK elements >= n
    length_ = 0;
    capacity_ = next_chunk(n);
    arena = static_cast<T *>(::operator new(sizeof(T) * capacity_));
    cout << ">>> arena created at " << (void *) arena << endl;
}

template<class T>
Vector<T>::~Vector()
{
    // Execute destructor for each element
    for (size_t i = 0; i < length_; ++i)
        (arena+i)->~T();

    ::operator delete(arena);
}

template<class T>
inline T& Vector<T>::operator[](size_t pos)
{
    if (pos >= length_)
        throw "bad index in Vector<T>::operator[]";
    return arena[pos];
}

template<class T>
inline size_t Vector<T>::length() const
{
    return length_;
}

template<class T>
inline size_t Vector<T>::capacity() const
{
    return capacity_;
}

template<class T>
void Vector<T>::reserve(size_t new_capacity)
{
    // Only allow an increase:
    if (new_capacity > capacity_)
    {
        new_capacity = next_chunk(new_capacity);
        if (new_capacity > capacity_)
        {
            // Copy elements to new space
            T *new_arena = static_cast<T*>(::operator new(sizeof(T)*new_capacity));
            cout << ">>> new arena created at "
                 << static_cast<void *>(new_arena) << endl;
            for (size_t i = 0; i < length_; ++i)
                new (new_arena + i) T(arena[i]);

            // Destroy old vector
            for (size_t i = 0; i < length_; ++i)
                (arena+i)->~T();
            delete arena;

            // Update state
            arena = new_arena;
            capacity_ = new_capacity;
        }
    }
}

template<class T>
void Vector<T>::resize(size_t new_length)
{
    // Only allow a decrease:
    if (new_length < length_)
    {
        // Just destroy truncated elements;
        // Don't change capacity
        for (int i = new_length; i < length_; ++i)
            (arena+i)->~T();
        length_ = new_length;
    }
}

template<class T>
Vector<T>& Vector<T>::operator+=(const T& x)
{
    if (length_ == capacity_)
        reserve(length_ + 1);
    new (arena + length_++) T(x);
    return *this;
}

template<class T>
inline size_t Vector<T>::next_chunk(size_t n)
{
    // Compute multiple of CHUNK >= n
    return ((n + CHUNK - 1) / CHUNK) * CHUNK;
}

