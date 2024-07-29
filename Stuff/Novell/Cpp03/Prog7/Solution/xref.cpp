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

char replaceDelim(char c)
{
   // Only keep alphas, space (as a delimiter), and '
   return (isalpha(c) || isspace(c) || c == '\'') ? c : ' ';
}

struct Nocase : binary_function<string, string, bool>
{
   int operator()(const string& s1, const string& s2)
   {
      int cmp = stricmp(s1.c_str(), s2.c_str());
      if (cmp == 0)
         return strcmp(s1.c_str(), s2.c_str()) < 0;
      return cmp < 0;
   }
};

void process(istream& f)
{
   typedef map<string, set<size_t>, Nocase> map_type;
   map_type mymap;
   string line;
   size_t lineno = 0;

   // Build map, reading a line at a time
   while (getline(f, line))
   {
      ++lineno;
      transform(line.begin(), line.end(), line.begin(), replaceDelim);
      istringstream is(line);
      string token;
      while (is >> token)
         mymap[token].insert(lineno);
   }

   // Print Output File
   for (map_type::iterator p = mymap.begin(); p != mymap.end(); ++p)
   {
      // Print the key in a field of width maxLength+1
      cout << p->first << ": ";

      // Process each line number in the set
      set<size_t>& s = p->second;
      set<size_t>::iterator iter = s.begin();
      while (iter != s.end())
         cout << *iter++ << ' ';
      cout << endl;
   }
}

int main(int argc, char* argv[])
{
   if (argc == 1)
      process(cin);
   else
   {
      ifstream f(argv[1]);
      if (f)
         process(f);
   }
}
