#include <iostream>
#include <algorithm>
using namespace std;

bool greaterThan15(int x)
{
   return x > 15;
}

bool greaterThan25(int x)
{
   return x > 25;
}

int main()
{
   int a[] = {10, 20, 30, 40};
   size_t size = sizeof a / sizeof a[0];
   int* endptr = a + size;

   // Do a simple find:
   int* p = find(a, endptr, 10);
   if (p != endptr)
      cout << "found " << *p << " in position " << p - a << endl;

   // Find the first greater than 15:
   p = find_if(a, endptr, greaterThan15);
   if (p != endptr)
      cout << "found " << *p << " in position " << p - a << endl;

   // Find the first greater than 25:
   p = find_if(a, endptr, greaterThan25);
   if (p != endptr)
      cout << "found " << *p << " in position " << p - a << endl;
}

/* Output:
found 10 in position 0
found 20 in position 1
found 30 in position 2
*/


