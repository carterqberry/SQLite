#include <cstddef>
using std::size_t;

class Pool
{
   char** pool;            // Our managed heap (a dynamic array of blocks)
   void* free;             // Pointer to free list
   const size_t elemSize;  // size of objects to manage
   const size_t blockSize; // number of elements in a block of objects
   size_t nBlocks;         // number of blocks allocated (length of heap)
   bool traceFlag;         // Debug trace flag
   
   // Disallow copy and assign
   Pool(const Pool&);
   Pool& operator=(const Pool&);

   // Internal utility functions
   static void storePtr(char* where, char* what)
   {
      // Store a char* (what) in an arbitrary location (where)
      char** loc = reinterpret_cast<char**>(where);
      *loc = what;
   }
   static char* getPtr(char* where)
   {
      // Return the char* stored at an arbitrary location (where)
      char** loc = reinterpret_cast<char**>(where);
      return *loc;
   }
   void link(char* base);
   void expand();

public:
   Pool(size_t elemSize, size_t blockSize = 100, bool traceFlag = false);
   ~Pool();
   void* allocate();       // Get a pointer to a new object
   void deallocate(void*); // Free an object's slot
   void trace(bool traceFlag)
   {
      this->traceFlag = traceFlag;
   }
};

