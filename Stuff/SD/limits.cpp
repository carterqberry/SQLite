#include <limits>
#include <iostream>
using namespace std;

int main() {
    cout << numeric_limits<int>::min() << endl;
    cout << numeric_limits<int>::max() << endl;
    cout << numeric_limits<int>::epsilon() << endl;
    cout << numeric_limits<int>::is_signed << endl;
    cout << numeric_limits<int>::is_integer << endl;
    cout << numeric_limits<int>::digits << endl;
    cout << numeric_limits<float>::min() << endl;
    cout << numeric_limits<float>::max() << endl;
    cout << numeric_limits<float>::epsilon() << endl;
    cout << numeric_limits<float>::is_signed << endl;
    cout << numeric_limits<float>::is_integer << endl;
    cout << numeric_limits<float>::digits << endl;
}
