#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>
using namespace std;

template<typename T, template<typename U, typename = allocator<U> >
         class Seq>
void printSeq(const Seq<T>& seq) {
    copy(seq.begin(), seq.end(), ostream_iterator<T>(cout, "\n"));
}

int main() {
  // Process a vector
  vector<int> v;
  v.push_back(1);
  v.push_back(2);
  printSeq(v);
  // Process a list
  list<int> lst;
  lst.push_back(3);
  lst.push_back(4);
  printSeq(lst);
}

