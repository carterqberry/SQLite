#include <exception>
#include <iostream>
using namespace std;

void handler()
{
    cerr << "unexpected exception\n";
    throw;
}

void g()
{
   throw 1;
}

void f() throw(bad_exception)
{
    g();
}

int main()
{
    set_unexpected(handler);
    try
    {
        f();
    }
    catch (bad_exception&)
    {
        cout << "caught exception\n";
    }
}

