// convert.cpp: Illustrates converting constructors
#include <iostream>
using namespace std;

class IntThing {
   int myValue;
public:
   IntThing(int x) {
      cout << "Creating an IntThing with value " << x << endl;
      myValue = x;
   }
   int getValue() const {
      return myValue;
   }
   IntThing& operator--() {
      --myValue;
      return *this;
   }
};

void printIntThing(const IntThing& it) {
   cout << "IntThing has value: " << it.getValue() << endl;
}

IntThing& decIntThing(IntThing& it) {
   --it;
   return it;
}

int main() {
   IntThing i(5);
   decIntThing(i);
   printIntThing(i);
   int j = 3;
   printIntThing(decIntThing(j));
   printIntThing(j);
}
