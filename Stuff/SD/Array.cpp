#include <cstddef>
#include <iostream>
using namespace std;

template<class T>
class Array { 
  enum { INIT = 10 };
  T* data;
  size_t capacity;
  size_t count;
public:
  Array() {
    count = 0;
    data = new T[capacity = INIT];
  }
  ~Array() { delete [] data; }
  void push_back(const T& t) {if (count < capacity) data[count++] = t;}
  void pop_back() {if (count > 0) --count;}
  T* begin() { return data; }
  T* end() { return data + count; }
};

template<>
class Array<void*> {
    enum { INIT = 10 };
    void** data;
    size_t capacity;
    size_t count;
  public:
    Array() {
      count = 0;
      data = new void*[capacity = INIT];
    }
    ~Array() { delete [] data; }
    void push_back(void* const & t) {if (count < capacity) data[count++] = t;}
    void pop_back() {if (count > 0) --count;}
    void** begin() { return data; }
    void** end() { return data + count; }
};

template<class T>
class Array<T*> : protected Array<void*> {
    typedef Array<void*> Base;
public:
    void push_back(T* const & t) { Base::push_back(t);}
    void pop_back() {Base::pop_back();}
    T** begin() { return reinterpret_cast<T**>(Base::begin()); }
    T** end() { return reinterpret_cast<T**>(Base::end()); }
};

int main() {
    Array<int*> a;
    int i = 1;
    int j = 2;
    a.push_back(&i);
    a.push_back(&j);
    int** p = a.begin();
    cout << **p << endl;
    cout << **++p << endl;
}
