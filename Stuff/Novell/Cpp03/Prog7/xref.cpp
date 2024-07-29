// xref.cpp: Prints a word-to-line number cross reference listing of a text file
//           Only tokens of alphabetic characters and "'" are recognized.
#include <algorithm>
#include <cstring>   // for strcmp and stricmp
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
using namespace std;

struct Nocase : binary_function<string, string, bool> {
   int operator()(const string& s1, const string& s2) {
      //?
   }
};

void process(istream& f) {
   typedef map<string, set<size_t>, Nocase> map_type;
   map_type mymap;
   string line;
   size_t lineno = 0;

   // Build map, reading a line at a time
   while (getline(f, line)) {
      //?
      // Read a line, replace characters to be ignored with spaces
      // Then extracts words with an istringstream using >>
      // (This is easier than using a tokenizer)
      // Then update the word's entry in the map by adding the current
      // line number.
   }

   // Print Output File
   for (map_type::iterator p = mymap.begin(); p != mymap.end(); ++p) {
      //?
      // Print the key followed by ": "

      // Print each line number in the set
   }
}

int main(int argc, char* argv[]) {
   if (argc == 1)
      process(cin);
   else {
      ifstream f(argv[1]);
      if (f)
         process(f);
   }
}
