#include <iostream>
using namespace std;

class MyObject
{
   static int counter; 

public:
   MyObject()
   {
      ++counter;
   }
   ~MyObject()
   {
      --counter;
   }
   static int getCount()
   {
      return counter;
   }
};

int MyObject::counter = 0;

// An object with static storage:
MyObject global;

int main()
{
   cout << "there are " << MyObject::getCount() << " objects\n";

   {
      MyObject* pDynamic = new MyObject;  // a heap object
      cout << "there are " << MyObject::getCount() << " objects\n";
      MyObject local;                     // a stack object
      cout << "there are " << MyObject::getCount() << " objects\n";
      delete pDynamic;  // must destroy heap object explicitly
      cout << "there are " << MyObject::getCount() << " objects\n";
   }

   cout << "there are " << MyObject::getCount() << " objects\n";
}

/* Output:
there are 1 objects
there are 2 objects
there are 3 objects
there are 2 objects
there are 1 objects
*/

