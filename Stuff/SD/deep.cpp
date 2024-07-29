#include <iostream>
using namespace std;

void h()
{
    cout << "doing h..." << endl;
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
    f();
    cout << "back in main" << endl;
}

/* Output:
doing h...
doing g...
doing f...
back in main
*/

