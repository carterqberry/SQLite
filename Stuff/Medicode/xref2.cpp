// STL3.cpp: Prints a word-to-line number cross reference listing of a text file
#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <sstream>
#include <string>
using namespace std;

int main() {
   map<string, set<int> > mymap;
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
   for (map<string, set<int> >::iterator p = mymap.begin(); p != mymap.end(); ++p) {
      cout << p->first << ": ";
      copy(p->second.begin(), p->second.end(), ostream_iterator<int>(cout, " "));
      cout << endl;
   }
}

