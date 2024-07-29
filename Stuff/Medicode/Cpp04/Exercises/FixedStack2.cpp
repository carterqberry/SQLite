#include <cassert>
#include <iostream>
#include <string>
using namespace std;

template<class T>
class FixedStack {
   T* data;
   int capacity;
   int count;
public:
   FixedStack(int cap) {
      data = new T[cap];
      capacity = cap;
      count = 0;
   }
   ~FixedStack() {
      delete [] data;
   }
   void push(T x) {
      assert(count < capacity);
      data[count++] = x;
   }
   T pop() {
      assert(count > 0);
      return data[--count];
   }
   T top() const {
      assert(count > 0);
      return data[count-1];
   }
   int size() const {
      return count;
   }
};

int main() {
   FixedStack<int> fs(5);
   for (int i = 0; i < 5; ++i)
      fs.push(i);
   while (fs.size() > 0)
      cout << fs.pop() << endl;

   FixedStack<double> fs2(5);
   for (int i = 0; i < 5; ++i)
      fs2.push(i*100.0);
   while (fs2.size() > 0)
      cout << fs2.pop() << endl;

   FixedStack<string> fs3(5);
   fs3.push("one");
   fs3.push("two");
   fs3.push("three");
   fs3.push("four");
   fs3.push("five");
   while (fs3.size() > 0)
      cout << fs3.pop() << endl;
}
