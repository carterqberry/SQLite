#include <iostream>
#include <string>
using namespace std;

const string vowels = "aAeEiIoOuU";

int countVowels(const string& s) {
   int count = 0;
   for (int i = 0; i < s.size(); ++i)
      if (vowels.find(s[i]) != string::npos)
         ++count;
   return count;
}

int main() {
   string line;
   for (int i = 1; getline(cin, line); ++i)
      cout << "line " << i << " has " << countVowels(line) << " vowels\n";
}

