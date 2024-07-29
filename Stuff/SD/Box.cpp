#include <iostream>
using namespace std;

template<typename T>
class Box {
   T value;
public:
   Box(const T& t) { value = t; }
   friend ostream& operator<<(ostream& os, const Box<T>& b)
   {
      return os << b.value;
   }
}; 

int main() {
    Box<int> b(2);
    cout << b << endl;
    Box<double> d(1.5);
    cout << d << endl;
}
