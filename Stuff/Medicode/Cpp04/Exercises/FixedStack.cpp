#include <cassert>
#include <iostream>
using namespace std;

class FixedStack {
   int* data;
   int capacity;
   int count;
public:
   FixedStack(int cap) {
      data = new int[cap];
      capacity = cap;
      count = 0;
   }
   ~FixedStack() {
      delete [] data;
   }
   void push(int x) {
      assert(count < capacity);
      data[count++] = x;
   }
   int pop() {
      assert(count > 0);
      return data[--count];
   }
   int top() const {
      assert(count > 0);
      return data[count-1];
   }
   int size() const {
      return count;
   }
};

int main() {
   FixedStack fs(5);
   for (int i = 0; i < 5; ++i)
      fs.push(i);
   while (fs.size() > 0)
      cout << fs.pop() << endl;
}
