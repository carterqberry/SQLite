// echo.cpp: Echoes command-line args,
// 1-per-line

#include <iostream>
#include "arglist.h"
using namespace std;

main(int argc, const char** argv)
{
    Arglist args(--argc, ++argv);
    for (int i = 0; i < args.count(); ++i)
        cout << args[i] << endl;
}
