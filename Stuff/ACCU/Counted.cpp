#include <iostream>
using namespace std;

class Counted {
   static int count;
public:
   Counted() {
      ++count;
   }
   ~Counted() {
      --count;
   }
   static int getCount() {
      return count;
   }
};

int Counted::count = 0;

int main() {
   Counted c;
   cout << Counted::getCount() << endl;
   {
      Counted c2;
      cout << Counted::getCount() << endl;
   }
   cout << Counted::getCount() << endl;
}

