#include <cassert>
#include <iostream>
#include <string>
using namespace std;

template<class T = int, int N = 5>
class FixedStack {
   T data[N];
   int count;
public:
   FixedStack() {
      count = 0;
   }
   void push(T x) {
      assert(count < N);
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
   FixedStack<> fs;
   for (int i = 0; i < 5; ++i)
      fs.push(i);
   while (fs.size() > 0)
      cout << fs.pop() << endl;

   FixedStack<double> fs2;
   for (int i = 0; i < 5; ++i)
      fs2.push(i*100.0);
   while (fs2.size() > 0)
      cout << fs2.pop() << endl;

   FixedStack<string,3> fs3;
   fs3.push("one");
   fs3.push("two");
   fs3.push("three");
   while (fs3.size() > 0)
      cout << fs3.pop() << endl;
}
