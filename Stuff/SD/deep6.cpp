#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

class MyError : public runtime_error
{
public:
    MyError(const string& s) : runtime_error(s) {}
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
    catch(exception& x)
    {
        cerr << typeid(x).name() << ':' 
             << x.what() << endl;
    }
    catch (...)	    // catch-all
    {
        cerr << "Unknown error\n";
    }

    cout << "back in main" << endl;
}

/* Output:
MyError: h() has a problem    [printed to cerr]
back in main                  [printed to cout]
*/

