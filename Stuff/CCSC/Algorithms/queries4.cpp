#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

typedef vector<int>::iterator iter;
void display(iter start, iter pos) {
    cout << "found " << *pos << " in position " << pos-start << endl;
}

int main() {
    vector<int> a;
    copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(a));
    iter p = find(a.begin(), a.end(), 3);
    if (p != a.end())
        display(a.begin(), p);
    p = find_if(a.begin(), a.end(), bind2nd(greater<int>(), 10));
    if (p != a.end())
        display(a.begin(), p);
    p = adjacent_find(a.begin(), a.end());
    if (p != a.end())
        display(a.begin(), p);
    cout << "# of 2's: " << count(a.begin(), a.end(), 2) << endl;
    cout << "# > 10: " << count_if(a.begin(), a.end(), bind2nd(greater<int>(), 10)) << endl;
}

/* Output:
found 3 in position 7
found 20 in position 2
found 2 in position 3
# of 2's: 2
# > 10: 2
*/
