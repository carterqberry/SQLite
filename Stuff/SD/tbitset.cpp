#include <bitset>
#include <iostream>
using namespace std;

int main()
{
   const int N = 10;
   bitset<N> b1;
   for (int i = 0; i < N; i+=2)
      b1.set(i);
   cout << b1 << endl;
   
   bitset<N> b2;
   for (int i = 1; i < N; i+=2)
      b2.set(i);
   cout << b2 << endl << endl;

   // Bitwise operations
   cout << (b1 & b2) << endl;
   cout << (b1 | b2) << endl;
   cout << (b1 ^ b2) << endl;
   cout << ~b1 << endl;
   cout.setf(ios::boolalpha);
   cout << (b1 == ~b2) << endl;
   cout << (b2 == (b1 << 1)) << endl << endl;

   // Subscripting
   bitset<N> b3;
   for (int i = 1; i < N; ++i)
      b3[i] = b2[i];
   cout << (b3 == b2) << endl;
   for (int i = 0; i < N; i+=2)
      b3[i] = b3[i+1];
   cout << b3 << endl;
   b3.flip();
   cout << (b3.to_ulong() == 0) << endl;
   b3.flip(0);
   cout << (b3.to_ulong() == 1) << endl << endl;

   // Miscellaneous
   cout << b1.any() << endl;
   cout << b1.none() << endl;
   cout << b1.count() << endl;
}

/* Output:
0101010101
1010101010

0000000000
1111111111
1010101010
true
true

true
1111111111
true
true

true
false
5
*/

