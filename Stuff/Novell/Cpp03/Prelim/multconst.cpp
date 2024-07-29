#include <iostream>
using namespace std;

int main()
{
   const char c = 'a';
   char* pc;
   const char** ppc = (const char**) &pc; // Make it legal
   *ppc = &c;
   *pc = 'b';
   cout << c << endl;
}

