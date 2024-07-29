// arglist.cpp
#include "arglist.h"
#include <fstream>
#include<cassert>
using namespace std;

Arglist::Arglist(int arg_count, const char **arg_vec)
{
    // Build complete argument vector
    for (int i = 0; i < arg_count; ++i)
        if (arg_vec[i][0] == '@')
            expand(arg_vec[i]+1);
        else
            add(arg_vec[i]);
}

const string& Arglist::operator[](size_t i) const
{
    assert(i < args.size());
    return args[i];
}

void Arglist::expand(const char* fname)
{
    ifstream f(fname);
    string token;

    while (f >> token)
        if (token[0] == '@')
            expand(token.c_str()+1);
        else
            add(token.c_str());
}

