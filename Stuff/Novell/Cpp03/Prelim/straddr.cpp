// Print the address of a C-style string
#include <iostream>
using namespace std;

int main() {
   char* s = "hello";
   char t[] = "hello";
   int i;
   cout << hex << &i << endl;
   cout << s << endl;
   cout << &s << endl;
   cout << static_cast<void*>(s) << endl;
   cout << t << endl;
   cout << &t << endl;
   cout << static_cast<void*>(t) << endl;
}

