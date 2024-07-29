// find3.cpp: Finds lines containing a given substring (Modern version)
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
    string line;

    if (argc > 1)
    {
       for (int lineno = 1; getline(cin, line); ++lineno)
       if (line.find(argv[1]) != string::npos)
          cout << lineno << ": " << line << endl;
    }
}


