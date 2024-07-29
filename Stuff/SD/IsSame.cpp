#include <iostream>
using namespace std;

template<typename T1, typename T2>
struct IsSame {
   enum { result = false };
};

template<typename T>
struct IsSame<T, T> {
   enum { result = true };
};

int main() {
   // Evaluated at compile time!
   const bool q1 = IsSame<int, int>::result;
   const bool q2 = IsSame<int, double>::result;

   cout << q1 << endl;  // 1
   cout << q2 << endl;  // 0
}

