#include <algorithm>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>
using namespace std;

string quote(const string& s) {
    return '"' + s + '"';
}


int main(int argc, char* argv[]) {
    if (argc == 3) {
        ifstream infile(argv[1]);
        ofstream outfile(argv[2]);
        transform(istream_iterator<string>(infile), istream_iterator<string>(),
                  ostream_iterator<string>(outfile,"\n"), quote);

        infile.close();
        ifstream infile2(argv[1]);
        cout << accumulate(istream_iterator<string>(infile2), istream_iterator<string>(),
                           string(""));
        cout << endl;
    }
    int nums[] = {1,2,3};
    int n = 2;
    transform(nums, nums+3, nums, bind2nd(plus<int>(),n));
    copy(nums,nums+3,ostream_iterator<int>(cout," "));
}
