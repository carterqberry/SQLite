#include <new>    // defines size_t (and other things we're not using yet)
#include <cstdlib>
#include <cstdio>
using namespace std;

class T
{
   int x;
public:
   T()
   {
      printf("Default ctor\n");
   }
   ~T()
   {
      printf("Destructor\n");
   }
};


void* operator new(size_t siz)
{
   void* p = std::malloc(siz);
   std::printf("Allocating %d bytes at %p\n", siz, p);
   return p; 
}

void operator delete(void* p)
{
   std::printf("Deleting memory at %p\n", p);
   std::free(p);
}

void* operator new[](size_t siz)
{
   void* p = std::malloc(siz);
   std::printf("Allocating an array of %d bytes at %p\n", siz, p);
   return p; 
}

void operator delete[](void* p)
{
   std::printf("Deleting an array at %p\n", p);
   std::free(p);
}

int main()
{
   T* p1 = new T;
   T* p2 = new T[10];
   delete p1;
   delete [] p2;
}

/* Output:
Allocating 4 bytes at 007A2E18
Allocating an array of 40 bytes at 007A2E28
Deleting memory at 007A2E18
Deleting an array at 007A2E28
*/

