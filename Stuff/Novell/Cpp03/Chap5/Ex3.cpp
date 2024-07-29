#include <algorithm>
#include <iostream>
using namespace std;

template<class T>
struct Sum {
   T total;
   Sum() {
      total = T();
   }
   void operator()(const T& t) {
      total += t;
      cout << "total " << total << endl;
   }
   T getTotal() const {
      cout << total << endl;
      return total;
   }
};
struct IntSum {
   int total;
   IntSum() {
      total = 0;
      cout << "Ctor\n";
   }
   ~IntSum() {
      cout << "dtor\n";
   }
   void operator()(const int& t) {
      total += t;
      cout << "total " << total << endl;
   }
   int getTotal() const {
      cout << total << endl;
      return total;
   }
};

int main() {
   int a[5] = {1,2,3,4,5};
   IntSum s;
   s = for_each(a,a+5,s);
   cout << s.getTotal() << endl;
}
