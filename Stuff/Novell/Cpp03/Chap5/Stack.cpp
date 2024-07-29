#include <cassert>
#include <cstddef>
#include <iostream>
#include <string>
using namespace std;

template<typename T, size_t N = 10>
class Stack {
   T data[N];
   size_t count;
public:
   Stack();
   void push(const T& x);
   T pop();
   T top() const;
   size_t size() const;
};

template<typename T, size_t N>
Stack<T, N>::Stack() {
   count = 0;
}
template<typename T, size_t N>
void Stack<T, N>::push(const T& x) {
   assert(count < N);
   data[count++] = x;
}
template<typename T, size_t N>
T Stack<T,N>::pop() {
   assert(count > 0);
   return data[--count];
}
template<typename T, size_t N>
T Stack<T,N>::top() const {
   assert(count > 0);
   return data[count - 1];
}
template<typename T, size_t N>
size_t Stack<T,N>::size() const {
   return count;
}

int main() {
   Stack<int> s;
   for (int i = 0; i < 10; ++i)
      s.push(i);
   while (s.size() > 0)
      cout << s.pop() << ' ';
   cout << endl;

   string text[] = {"one", "two", "three", "four", "five"};
   Stack<string, 5> ss;
   for (size_t i = 0; i < sizeof text / sizeof text[0]; ++i)
      ss.push(text[i]);
   while (ss.size() > 0)
      cout << ss.pop() << ' ';
   cout << endl;
}

