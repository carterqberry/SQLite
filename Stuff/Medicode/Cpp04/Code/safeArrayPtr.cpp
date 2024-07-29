#include <iostream>
#include <cassert>
using namespace std;

template<typename T>
class SafeArrayPtr
{
   T* const base;
   T* ptr;
   size_t size;

   // Disallow copy and assignment
   SafeArrayPtr(const SafeArrayPtr&);
   SafeArrayPtr& operator=(const SafeArrayPtr&);

public:
   explicit SafeArrayPtr(T* ptr, size_t size)
      : base(ptr)
   {
      cout << "SafeArrayPtr initialized\n";
      this->ptr = ptr;
      this->size = size;
   }
   T& operator*()
   {
      cout << "Executing SafeArrayPtr::operator*\n";
      return *ptr;
   }
   T* operator++()
   {
      cout << "pre-increment ";
      assert(ptr < base + size);
      return ++ptr;
   }
   const T* operator++(int)
   {
      cout << "post-increment ";
      assert(ptr < base + size);
      T* current = ptr;
      ++ptr;
      return current;
   }
   T* operator--()
   {
      cout << "pre-decrement ";
      assert(ptr > base);
      return --ptr;
   }
   const T* operator--(int)
   {
      cout << "post-decrement ";
      assert(ptr > base);
      T* current = ptr;
      --ptr;
      return current;
   }
};

int main()
{
   int a[] = {10, 20, 30};
   size_t n = sizeof a / sizeof a[0];
   SafeArrayPtr<int> p(a, n);

   // Traverse up
   for (size_t i = 0; i < n; ++i)
      cout << *p++ << endl;

   // Traverse back down
   for (size_t i = 0; i < n; ++i)
      cout << *--p << endl;

   // Try to go off left end
   cout << *p-- << endl;
}

/* Output:
SafeArrayPtr initialized
post-increment 10
post-increment 20
post-increment 30
pre-decrement 30
pre-decrement 20
pre-decrement 10
post-decrement 
Assertion failed: ptr > base, file C:\UVSC\Spring02\3370\safeArrayPtr.cpp, line 52

Abnormal program termination
*/

