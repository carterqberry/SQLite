#include <iostream>
using namespace std;

int main()
{
   char c0 = 'a';
   const char& c = c0;
   char* pc;
   const char** ppc = (const char**) &pc; // Make it legal
   *ppc = &c;
   *pc = 'b';
   cout << c << endl;
}

