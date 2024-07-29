// merge.cpp: Merge two sorted files to standard output
#include <iostream>
#include <fstream>
#include <cstring>         // For strcmp()
#include <cstdlib>         // For EXIT codes
#include <cassert>
using namespace std;

int main(int argc, char *argv[])
{
    char buf1[BUFSIZ], buf2[BUFSIZ];

    // Open files:
    if (argc != 3)
        return EXIT_FAILURE;
    ifstream f1(argv[1]);
    ifstream f2(argv[2]);

    // Do the merge:
    f1.getline(buf1,BUFSIZ);
    f2.getline(buf2,BUFSIZ);
    while (f1 && f2)
    {
        // (INVARIANT: both buffers have fresh lines)

        // Print and refresh the appropriate line:
        if (strcmp(buf1,buf2) <= 0)
        {
            cout << buf1 << endl;
            f1.getline(buf1,BUFSIZ);
        }
        else
        {
            cout << buf2 << endl;
            f2.getline(buf2,BUFSIZ);
        }
    }
    // (INVARIANT: At least one file has been exhausted)

    // Empty the remaining file:
    while (f1)
    {
        // (INVARIANT: buf1 has a fresh line)
        cout << buf1 << endl;
        f1.getline(buf1,BUFSIZ);
    }
    assert(f1.eof());     // (INVARIANT: file1 has been exhausted)

    while (f2)
    {
        // (INVARIANT: buf2 has a fresh line)
        cout << buf2 << endl;
        f2.getline(buf2,BUFSIZ);
    }
    assert(f2.eof());     // (INVARIANT: file2 has been exhausted)

    return EXIT_SUCCESS;
}

