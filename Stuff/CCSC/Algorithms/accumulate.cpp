// fun sqsum nums = foldl (fn (a,b) => a * a + b) 0 nums;

#include <iostream>
#include <numeric>
using namespace std;

int sum_sofar(int b, int a) {
    return a*a + b;
}

int main() {
    int a[] = {1,2,3,4};
    cout << accumulate(a, a+4, 0, sum_sofar) << endl;
    cout << accumulate(a, a+4, 1, multiplies<int>());
}
