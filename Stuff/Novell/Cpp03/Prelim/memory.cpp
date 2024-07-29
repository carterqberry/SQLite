#include <new>    // defines size_t (and other things we're not using yet)
#include <cstdlib>
#include <cstdio>

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
   int* p1 = new int;
   int* p2 = new int[10];
   delete p1;
   delete [] p2;
}

/* Output:
Allocating 4 bytes at 007A2E18
Allocating an array of 40 bytes at 007A2E28
Deleting memory at 007A2E18
Deleting an array at 007A2E28
*/

