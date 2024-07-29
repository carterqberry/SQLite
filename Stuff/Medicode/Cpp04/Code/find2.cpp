// find2.cpp: Finds lines containing a given substring
#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, char* argv[])
{
    char line[BUFSIZ];

    if (argc > 1)
    {
       for (int lineno = 1; gets(line) != 0; ++lineno)
          if (strstr(line,argv[1]))
             cout << lineno << ": " << line << endl;
    }
}


