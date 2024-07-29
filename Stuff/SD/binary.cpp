// binary.cpp: A glance at template metaprogramming
#include <iostream>
using namespace std;

// Templates for computing binary numbers at compile time.
// The template parameter is a long to maximize the size
// of the binary number we can convert. The result will fit 
// in an unsigned int. Only compile-time operators and
// types can be used.
template<unsigned long N>
struct binary {
   static const unsigned int value =
      binary<N/10>::value << 1 | N%10;
};

// A (full, in this case) specialization to stop the recursion.
template<>
struct binary<0> {
   static const unsigned int value = 0;
};

int main() {
   cout << binary<101>::value << endl;          // 5
   cout << binary<1001101110>::value << endl;   // ?
   cout << binary<11100111>::value << endl;   // ?
}


