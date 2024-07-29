#include <iostream>
using namespace std;

class MyObject
{
   int id;
public:
   MyObject(int id)
   {
      cout << "Creating object #" << id << endl;
      this->id = id;
   }
   ~MyObject()
   {
      cout << "Destroying object #" << id << endl;
   }
};


// An object with static storage:
MyObject global(1);

int main()
{
   MyObject* pDynamic = new MyObject(2);  // a heap object
   MyObject local(3);                     // a stack object
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

