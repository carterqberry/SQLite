// STL1.cpp: Performs operations on a sequence of numbers
#include <algorithm>
#include <cassert>
#include <functional>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>
using namespace std;

int main() {
	vector<int> nums;

	// Read numbers (until EOF) into vector
	copy(istream_iterator<int>(cin), istream_iterator<int>(),
        back_inserter(nums));

	// Find sum, average, min, max
	int n = nums.size();
	int sum = accumulate(nums.begin(), nums.end(), 0);
	double avg = double(sum) / n;
	int min = *min_element(nums.begin(), nums.end());
	int max = *max_element(nums.begin(), nums.end());
	cout << "There were " << n << " numbers read: ";
	copy(nums.begin(), nums.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	cout << "The sum is " << sum << endl;
	cout << "The average is " << avg << endl;
	cout << "The minimum is " << min << endl;
	cout << "The maximum is " << max << endl;

	// Sort a copy
	vector<int> nums2;
	copy(nums.begin(), nums.end(), back_inserter(nums2));	// Make a copy
	sort(nums2.begin(), nums2.end());
	cout << "Ascending order: ";
	copy(nums2.begin(), nums2.end(), ostream_iterator<int>(cout, " "));
	sort(nums2.begin(), nums2.end(), greater_equal<int>());
	cout << "\nDescending order: ";
	copy(nums2.begin(), nums2.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	// Extract elements
	cout << "Greater than 10: ";
	remove_copy_if(nums.begin(), nums.end(), ostream_iterator<int>(cout, " "),
		bind2nd(less_equal<int>(), 10));
	cout << endl;
	cout << "First number greater than 10: ";
	cout << *find_if(nums.begin(), nums2.end(),
                    bind2nd(greater<int>(),10)) << endl;

	// Make changes (in a copy)
	transform(nums.begin(), nums.end(), nums2.begin(),
             bind1st(plus<int>(), 3));
	cout << "After adding 3: ";
	copy(nums2.begin(), nums2.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	transform(nums2.begin(), nums2.end(), nums2.begin(), bind2nd(minus<int>(), 3));
	cout << "After subtracting the 3 out again: ";
	copy(nums2.begin(), nums2.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	assert(equal(nums.begin(), nums.end(), nums2.begin()));
}

/* Output:
There were 11 numbers read: 45 76 43 89 24 64 80 3 22 66 2 
The sum is 514
The average is 46.7273
The minimum is 2
The maximum is 89
Ascending order: 2 3 22 24 43 45 64 66 76 80 89 
Descending order: 89 80 76 66 64 45 43 24 22 3 2 
Greater than 10: 45 76 43 89 24 64 80 22 66 
First number greater than 10: 45
After adding 3: 48 79 46 92 27 67 83 6 25 69 5 
After subtracting the 3 out again: 45 76 43 89 24 64 80 3 22 66 2 
*/
