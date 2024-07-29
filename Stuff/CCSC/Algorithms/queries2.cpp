#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

bool gt10(int n) {
    return n > 10;
}

typedef vector<int>::iterator iter;
void display(iter start, iter end, iter pos) {
    if (start != end)
        cout << "found " << *pos << " in position " << pos-start << endl;
}

int main() {
    vector<int> a;
    copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(a));
    iter p = find(a.begin(), a.end(), 3);
    display(a.begin(), a.end(), p);
    p = find_if(a.begin(), a.end(), gt10);
    display(a.begin(), a.end(), p);
    p = adjacent_find(a.begin(), a.end());
    display(a.begin(), a.end(), p);
    cout << "# of 2's: " << count(a.begin(), a.end(), 2) << endl;
    cout << "# > 10: " << count_if(a.begin(), a.end(), gt10) << endl;
}

/* Output:
found 3 in position 7
found 20 in position 2
found 2 in position 3
# of 2's: 2
# > 10: 2
*/
