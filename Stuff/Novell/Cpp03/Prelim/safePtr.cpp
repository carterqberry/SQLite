#include <iostream>
using namespace std;

template<typename T>
class SafePtr
{
   T* ptr;

   // Disallow copy and assignment
   SafePtr(const SafePtr&);
   SafePtr& operator=(const SafePtr&);

public:
   explicit SafePtr(T* ptr)
   {
      cout << "SafePtr initialized\n";
      this->ptr = ptr;
   }
   ~SafePtr()
   {
      delete ptr;
      cout << "SafePtr memory released\n";
   }
   T* operator->()
   {
      cout << "Executing SafePtr::operator->\n";
      return ptr;
   }
   T& operator*()
   {
      cout << "Executing SafePtr::operator*\n";
      return *ptr;
   }
};

struct MyData
{
   int x;
   double y;
   MyData(int x, double y)
   {
      this->x = x;
      this->y = y;
   }
};

int main()
{
   SafePtr<MyData> p(new MyData(1,2.5));  // = syntax fails here
   MyData d = *p;
   cout << d.x << ", " << d.y << endl;
   cout << p->x << ", " << p->y << endl;
   // ++p; // error! (Thank goodness)
}

/* Output:
SafePtr initialized
Executing SafePtr::operator*
1, 2.5
Executing SafePtr::operator->
Executing SafePtr::operator->
1, 2.5
SafePtr memory released
*/

