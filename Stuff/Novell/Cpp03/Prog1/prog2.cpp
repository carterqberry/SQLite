#include <iostream>
#include <string>
#include <sstream>
#include "MyObject2.h"
using namespace std;

// The following function template converts an object of
// any type that supports operator << to a string
template<typename T>
string toString(const T& t)
{
   ostringstream os;
   os << t;
   return os.str();
}

int main()
{
   // Create an array of MyObject heap objects
   const size_t MAXOBJS = 100;
   MyObject* objs[MAXOBJS];
   for (int i = 0; i < MAXOBJS; ++i)
      objs[i] = MyObject::create(i, "\"" + toString(i) + "\"");
   cout << "Object 5 == " << *objs[5] << endl;
   delete objs[5];
   objs[5] = 0;

   cout << "Creating another object:\n";
   MyObject* anotherObject = MyObject::create(100, "anotherObject");
   cout << "anotherObject == " << *anotherObject << endl;

   cout << "Creating yet another object:\n";
   MyObject* yetAnotherObject = MyObject::create(120, "yetAnotherObject");
   cout << "yetAnotherObject == " << *yetAnotherObject << endl;
   
   // Delete everything (although it's not "necessary"!)
   delete anotherObject;
   delete yetAnotherObject;
   for (int i = 0; i < MAXOBJS; ++i)
      delete objs[i];
}

/* Output without trace:
Object 5 == {5,"5"}
Creating another object:
anotherObject == {100,anotherObject}
Creating yet another object:
yetAnotherObject == {120,yetAnotherObject}
*/

/* Output with trace:
Initializing a pool with element size 20 and block size 5
Expanding pool...
Linking cells starting at 00853C98
Cell allocated at 00853C98
Cell allocated at 00853CAC
Cell allocated at 00853CC0
Cell allocated at 00853CD4
Cell allocated at 00853CE8
Expanding pool...
Linking cells starting at 00854380
Cell allocated at 00854380
Cell allocated at 00854394
Cell allocated at 008543A8
Cell allocated at 008543BC
Cell allocated at 008543D0
Object 5 == {5,"5"}
Cell deallocated at 00854380
Creating another object:
Cell allocated at 00854380
anotherObject == {100,anotherObject}
Creating yet another object:
Expanding pool...
Linking cells starting at 0085478C
Cell allocated at 0085478C
yetAnotherObject == {120,yetAnotherObject}
Cell deallocated at 00854380
Cell deallocated at 0085478C
Cell deallocated at 00853C98
Cell deallocated at 00853CAC
Cell deallocated at 00853CC0
Cell deallocated at 00853CD4
Cell deallocated at 00853CE8
Cell deallocated at 00854394
Cell deallocated at 008543A8
Cell deallocated at 008543BC
Cell deallocated at 008543D0
Deleting 3 blocks
*/

