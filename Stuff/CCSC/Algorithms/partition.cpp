#include <algorithm>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

int main() {
    int a[5];
    generate_n(a, 5, rand);
    copy(a, a+5, ostream_iterator<int>(cout," "));
    cout << endl;
    int* p = partition(a, a+5, bind2nd(greater<int>(),16384));
    copy(a, p, ostream_iterator<int>(cout," "));
    cout << endl;
    copy(p, a+5, ostream_iterator<int>(cout," "));
}
