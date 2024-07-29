#include <iostream>
using namespace std;

class MyObject
{
   int id;
   static int counter;  // declaration

public:
   MyObject()
   {
      id = ++counter;
      cout << "Creating object #" << id << endl;
   }
   ~MyObject()
   {
      cout << "Destroying object #" << id << endl;
   }
};

// Must define statics outside the class
// (Don't use the keyword static here):
int MyObject::counter = 0;

// An object with static storage:
MyObject global;

int main()
{
   MyObject* pDynamic = new MyObject;  // a heap object
   MyObject local;                     // a stack object
   delete pDynamic;  // must destroy heap object explicitly
}

/* Output:
Creating object #1
Creating object #2
Creating object #3
Destroying object #2
Destroying object #3
Destroying object #1
*/

