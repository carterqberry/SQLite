#include "pool.h"
#include <string>
#include <iosfwd>
using std::string;
using std::ostream;

class MyObject
{
   int id;
   string name;
   static Pool pool;    // A private heap for all MyObjects

   // Disallow copy, assign, and direct construction
   MyObject(const MyObject&);
   MyObject& operator=(const MyObject&);
   MyObject(int i, const string& nm)
      : name(nm)
   {
      id = i;
   }
   
public:
   static void* operator new(size_t)
   {
      return pool.allocate();
   }
   static void operator delete(void* p)
   {
      pool.deallocate(p);
   }
   static MyObject* create(int id, const string& name) // Factory method
   {
      return new MyObject(id, name);
   }
   friend ostream& operator<<(ostream&, const MyObject&);
};

