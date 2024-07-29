#include <cassert>
#include <iostream>
#include <string>
using namespace std;

template<class T, int N>
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
   FixedStack<int,5> fs;
   for (int i = 0; i < 5; ++i)
      fs.push(i);
   while (fs.size() > 0)
      cout << fs.pop() << endl;

   FixedStack<double,5> fs2;
   for (int i = 0; i < 5; ++i)
      fs2.push(i*100.0);
   while (fs2.size() > 0)
      cout << fs2.pop() << endl;

   FixedStack<string,5> fs3;
   fs3.push("one");
   fs3.push("two");
   fs3.push("three");
   fs3.push("four");
   fs3.push("five");
   while (fs3.size() > 0)
      cout << fs3.pop() << endl;
}
