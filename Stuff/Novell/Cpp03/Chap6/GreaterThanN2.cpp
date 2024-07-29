#include <functional>
#include <iostream>
using namespace std;

int main() {
  greater<int> g;
  cout << g(3, 4) << endl;  // Prints 0 (for false)
  cout << g(5, 4) << endl;  // Prints 1 (for true)
} 

