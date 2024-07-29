// factorial.cpp
#include <iostream>
#include <cassert>
#include <iomanip>
using namespace std;

int fact(int n)
{
   assert(n >= 0);
   int result;

   // Track level of recursion
   static int level = 0;

   ++level;
   cout << setw(level*3) << ' ' << "fact(" << n << ")\n";

   if (n <= 1)
      result = 1;
   else
      result = n * fact(n-1);

   cout << setw(level*3) << ' ' << "returning " << result << endl;
   --level;
   return result;
}

int main()
{
   cout << fact(10) << endl;
}

