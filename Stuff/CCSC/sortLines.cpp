// A typical, CS1 example
// Sorts lines from standard input

#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
using namespace std;

int main() {
   vector<string> lines;
   string line;
   while (getline(cin, line))
      lines.push_back(line);
   sort(lines.begin(), lines.end());
   copy(lines.begin(), lines.end(), ostream_iterator<string>(cout, "\n"));
}
