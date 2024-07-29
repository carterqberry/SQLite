#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
using namespace std;

int main() {
   int a[] = {10, 20, 30};
   remove_copy_if(a, a+3, ostream_iterator<int>(cout, "\n"),
                  bind2nd(less<int>(), 15));
}

/* Output:
20
30
*/
