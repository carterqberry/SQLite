#include <iostream>
using namespace std;

int h()
{
    return 1;
}

int g()
{
    int rc = h();
    if (rc)
        return rc;
    cout << "doing g..." << endl;
    return 0;
}

int f()
{
    int rc = g();
    if (rc)
        return rc;
    cout << "doing f..." << endl;
    return 0;
}

int main()
{
    cout << "Return code: " << f() << endl;
    cout << "back in main" << endl;
}

/* Output:
Return code: 1
back in main
*/

