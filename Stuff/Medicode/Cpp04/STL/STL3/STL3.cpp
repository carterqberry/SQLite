// STL3.cpp: Prints a word-to-line number cross reference listing of a text file
#include <algorithm>
#include <cstring>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <sstream>
#include <string>
using namespace std;

// Function object to compare strings ignoring case
struct Nocase {
   bool operator()(const string& s1, const string& s2) {
      int comp = stricmp(s1.c_str(), s2.c_str());
      if (comp == 0)
         comp = strcmp(s1.c_str(), s2.c_str());
      return comp < 0;
   }
};

int main() {
   map<string, set<int>, Nocase > mymap;
   string line;
   int lineno = 0;

   // Build map, reading a line at a time
   while (getline(cin, line)) {
      ++lineno;
      istringstream is(line);
      string token;
      while (is >> token)
         mymap[token].insert(lineno);
   }

   // Print Output Report
   for (map<string, set<int>, Nocase >::iterator p = mymap.begin();
         p != mymap.end(); ++p) {
      cout << p->first << ": ";
      copy(p->second.begin(), p->second.end(),
           ostream_iterator<int>(cout, " "));
      cout << endl;
   }
}
