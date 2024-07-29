#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
using namespace std;

bool isBlank(const string& s) {
   return s.size() == 0 ||
      s.find_first_not_of(" \t\n\v\r\b") == string::npos;
}

int main() {
   // Read lines
   vector<string> lines;
   copy(istream_iterator<string>(cin), istream_iterator<string>(),
        back_inserter(lines));
   
   // Remove blank lines
   remove_if(lines.begin(), lines.end(), isBlank);

   // Sort descending
   sort(lines.begin(), lines.end(), greater<string>());

   // Remove duplicates
   vector<string>::iterator endIter =
      unique(lines.begin(), lines.end());

   // Print
   lines.resize(endIter - lines.begin());
   copy(lines.begin(), lines.end(), ostream_iterator<string>(cout, "\n"));
}
   
      
