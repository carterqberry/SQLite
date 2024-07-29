#include <algorithm>
#include <functional>
#include <numeric>
#include <iterator>
#include <iostream>
using namespace std;

int main()
{
    int a[5] = {1,2,3,4,5};
    int b[5] = {6,7,8,9,0};
    
    cout << inner_product(a,a+5,b,0) << endl;
    cout << inner_product(a,a+5,b,1,
                          multiplies<int>(),
                          plus<int>()) << endl;
    
    partial_sum(a,a+5,
        ostream_iterator<int>(cout," "));
    cout << endl;
    
    adjacent_difference(b,b+5,
        ostream_iterator<int>(cout," "));
    cout << endl;
}
