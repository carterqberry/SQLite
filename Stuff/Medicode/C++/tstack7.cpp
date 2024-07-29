// tstack7.cpp
#include <iostream>
#include <typeinfo>
#include "stack7.h"
using namespace std;

int main()
{
    try
    {
        StackOfInt stk(5);
    
        for (int i = 0; i < 10; ++i)
            stk.push(i*i);
        cout << stk << endl;
    }
    catch (exception& x)
    {
        cout << typeid(x).name() << ':' << x.what() << endl;
    }
}

/* Output:
Growing array to 15 ...
{0,1,4,9,16,25,36,49,64,81}
*/

