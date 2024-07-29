#include <iostream>
#include <algorithm>
using namespace std;

struct FindGreaterThan
{
   int key;
   FindGreaterThan(int n)
   {
      key = n;
   }
   bool operator()(int x)
   {
      cout << "Executing operator() with key of " << key << endl;
      return x > key;
   }
};

int main()
{
   int a[] = {10, 20, 30, 40};
   size_t size = sizeof a / sizeof a[0];
   int* endptr = a + size;

   // Do a simple find:
   int* p = find(a, endptr, 10);
   if (p != endptr)
      cout << "found " << *p << " in position " << p - a << endl;
   cout << endl;

   // Find the first greater than 15:
   p = find_if(a, endptr, FindGreaterThan(15));
   if (p != endptr)
      cout << "found " << *p << " in position " << p - a << endl;
   cout << endl;

   // Find the first greater than 25:
   p = find_if(a, endptr, FindGreaterThan(25));
   if (p != endptr)
      cout << "found " << *p << " in position " << p - a << endl;
   cout << endl;

   // Find the first greater than 35:
   p = find_if(a, endptr, FindGreaterThan(35));
   if (p != endptr)
      cout << "found " << *p << " in position " << p - a << endl;
   cout << endl;

   // Find the first greater than 45:
   p = find_if(a, endptr, FindGreaterThan(45));
   if (p != endptr)
      cout << "found " << *p << " in position " << p - a << endl;
   else if (p == endptr)
      cout << "45 not found\n";
}

/* Output:
found 10 in position 0

Executing operator() with key of 15
Executing operator() with key of 15
found 20 in position 1

Executing operator() with key of 25
Executing operator() with key of 25
Executing operator() with key of 25
found 30 in position 2

Executing operator() with key of 35
Executing operator() with key of 35
Executing operator() with key of 35
Executing operator() with key of 35
found 40 in position 3

Executing operator() with key of 45
Executing operator() with key of 45
Executing operator() with key of 45
Executing operator() with key of 45
45 not found
*/


