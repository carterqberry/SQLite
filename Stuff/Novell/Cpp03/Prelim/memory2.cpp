#include <new>    // defines size_t (and other things we're not using yet)
#include <cstdlib>
#include <cstdio>

class MyClass
{
   int x;
   int y;
public:
   // These are all implicitly static member functions...
   static void* operator new(size_t siz)
   {
      void* p = ::operator new(siz);
      std::printf("Allocating a MyClass object (%d bytes) at %p\n", siz, p);
      return p; 
   }
   
   static void operator delete(void* p)
   {
      std::printf("Deleting a MyClass object at %p\n", p);
      ::operator delete(p);
   }
   
   static void* operator new[](size_t siz)
   {
      void* p = ::operator new(siz);
      std::printf("Allocating an array of MyClass objects (%d bytes) at %p\n", siz, p);
      return p; 
   }
   
   static void operator delete[](void* p)
   {
      std::printf("Deleting an array of MyClass objects at %p\n", p);
      ::operator delete[](p);
   }
};

int main()
{
   MyClass* p1 = new MyClass;
   MyClass* p2 = new MyClass[10];
   delete p1;
   delete [] p2;
}

/* Output:
Allocating a MyClass object (8 bytes) at 007A2E1C
Allocating an array of MyClass objects (80 bytes) at 007A2E2C
Deleting a MyClass object at 007A2E1C
Deleting an array of MyClass objects at 007A2E2C
*/

