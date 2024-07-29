// Read an array of ints from standard input
#include <algorithm>
#include <iostream>
#include <iterator>
using namespace std;

int main()
{
   const int MAXNUMS = 10;
   int nums[MAXNUMS];
   int n;

   // Input loop
   for (n = 0; n < MAXNUMS && cin >> nums[n]; ++n)
      ;

   // Print array
   cout << "There are " << n << " numbers:\n";
   for (int i = 0; i < n; ++i)
      cout << nums[i] << ' ';
   cout << endl;

   // More modernly
   copy(nums, nums+n, ostream_iterator<int>(cout, " "));
}
