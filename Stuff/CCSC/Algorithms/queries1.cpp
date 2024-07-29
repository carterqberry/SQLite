#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool gt10(int n) {
    return n > 10;
}

void display(int* start, int* end, int* pos) {
    if (start != end)
        cout << "found " << *pos << " in position " << pos-start << endl;
}

int main() {
    int a[] = {10, 1, 20, 2, 2, 1, 30, 3};
    const int N = sizeof a / sizeof a[0];
    int* p = find(a, a+N, 3);
    display(a, a+N, p);
    p = find_if(a, a+N, gt10);
    display(a, a+N, p);
    p = adjacent_find(a, a+N);
    display(a, a+N, p);
    cout << "# of 2's: " << count(a, a+N, 2) << endl;
    cout << "# > 10: " << count_if(a, a+N, gt10) << endl;
}

/* Output:
found 3 in position 7
found 20 in position 2
found 2 in position 3
# of 2's: 2
# > 10: 2
*/
