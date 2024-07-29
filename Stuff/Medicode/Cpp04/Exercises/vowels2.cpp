#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

bool isVowel(char c) {
   static const string vowels = "aAeEiIoOuU";
   return vowels.find(c) != string::npos;
}

int main() {
   string line;
   for (int i = 1; getline(cin, line); ++i)
      cout << "line " << i << " has "
           << count_if(line.begin(), line.end(), isVowel) << " vowels\n";
}

