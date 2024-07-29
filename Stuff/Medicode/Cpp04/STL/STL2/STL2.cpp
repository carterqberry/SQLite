// STL2.cpp: Counts "words" in a text stream
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	map<string, int> counts;
	string word;

	// Track count of each word
	while (cin >> word)
		counts[word]++;

	// Print result (in ascending order by default!)
	map<string, int>::iterator iter = counts.begin();
	while (iter != counts.end()) {
		cout << iter->first << ": " << iter->second << endl;
		++iter;
	}
}