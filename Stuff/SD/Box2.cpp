#include <iostream>
using namespace std;

template<class T>
class Box {
   T value;
public:
   Box(const T& t) { value = t; }
   template<class U>
   friend void f(const Box<T>& b, const U& u) {
       cout << "u: " << u << ", b: " << b.value << endl;
   }
}; 

int main() {
    Box<int> b(2);
    f(b, 1.0);
    Box<double> d(1.5);
    f(d, 5);
}

/* Output:
u: 1, b: 2
u: 5, b: 1.5
*/
