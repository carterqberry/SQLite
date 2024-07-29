// find.cpp: Prints lines containing the substring "int"
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char line[BUFSIZ];

    for (int lineno = 1; gets(line) != 0; ++lineno)
       if (strstr(line,"int"))
          cout << lineno << ": " << line << endl;
}


