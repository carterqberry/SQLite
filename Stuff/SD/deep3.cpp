#include <iostream>
using namespace std;

void h()
{
    throw "h() has a problem";
}

void g()
{
    h();
    cout << "doing g..." << endl;
}

void f()
{
    g();
    cout << "doing f..." << endl;
}

int main()
{
    try
    {
        f();
    }
    catch(const char* msg)
    {
        cerr << "Error: " << msg << endl;
    }

    cout << "back in main" << endl;
}

/* Output:
Error: h() has a problem    [printed to cerr]
back in main                [printed to cout]
*/

