#include <iostream>
#include <string>
using namespace std;

class MyError
{
    string msg;
public:
    MyError(const string& s) : msg(s) {}
    string what() {return msg;}
};

void h()
{
    throw MyError("h() has a problem");
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
    catch(MyError& x)
    {
        cerr << "MyError: " << x.what() << endl;
    }
    catch(...)
    {
        cerr << "What happened" << endl;
    }

    cout << "back in main" << endl;
}

/* Output:
MyError: h() has a problem    [printed to cerr]
back in main                  [printed to cout]
*/

