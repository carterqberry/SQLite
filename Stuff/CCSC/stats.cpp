// Reads numbers from standard input
// Computes sum and average

#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>
using namespace std;

int main() {
   vector<int> nums;
   copy(istream_iterator<int>(cin), istream_iterator<int>(),
        back_inserter(nums));
   int sum = accumulate(nums.begin(), nums.end(), 0);
   double avg = sum / nums.size();
   cout << "sum = " << sum << endl;
   cout << "average = " << avg << endl;
}


