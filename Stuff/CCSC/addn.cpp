// addn.cpp: Illustrates higher-order functions in C++ (using function objects)
#include <iostream>
#include <algorithm>
#include <functional>
#include <iterator>
using namespace std;

// A function object that adds its argument to a fixed value
class g {
   int x;
public:
   g(int arg) : x(arg) {}
   int operator()(int y) {
      return x + y;
   }
};

int main() {
   // Invoke g(2)(3) two ways
   cout << g(2)(3) << endl;
   g f(2);
   cout << f(3) << endl;

   // The standard C++ way (bind2nd is a higher-order function)
   cout << bind2nd(plus<int>(), 2)(3) << endl;

   // Using a higher-order function in another higher-order function
   int nums[] = {1,2,3,4};
   transform(nums, nums+4, nums, bind2nd(plus<int>(), 2));
   copy(nums, nums+4, ostream_iterator<int>(cout, " "));
   cout << endl;
}

/* Output:
5
5
5
3 4 5 6 
*/

