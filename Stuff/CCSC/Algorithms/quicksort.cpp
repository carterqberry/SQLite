#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

template<class Iter>
void quicksort(Iter b, Iter e) {
    if (e - b > 1) {
        Iter mid =
            partition(b, e, bind2nd(less<typename Iter::value_type>(), *b));
        Iter right = 
            partition(mid, e, bind2nd(equal_to<typename Iter::value_type>(), *b));
        if (mid < e) {
            quicksort(b,mid);
            quicksort(right,e);
        }
    }
}

int main() {
    vector<string> stuff;
    stuff.push_back("brown");
    stuff.push_back("cow");
    stuff.push_back("how");
    stuff.push_back("now");
    while(next_permutation(stuff.begin(), stuff.end())) {
        vector<string> temp(stuff.begin(), stuff.end());
        quicksort(temp.begin(), temp.end());
        copy(temp.begin(), temp.end(), ostream_iterator<string>(cout, " "));
        cout << endl;
    }
}
