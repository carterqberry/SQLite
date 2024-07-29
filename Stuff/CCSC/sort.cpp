#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
using namespace std;

int main() {
   int a[] = {4,2,7,1,9};

   // Sort descending
   sort(a, a+5, greater<int>());
   copy(a, a+5, ostream_iterator<int>(cout, " "));
   cout << endl;
}
