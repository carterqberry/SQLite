// tstack5b.cpp
#include <iostream>
#include "stack5b.h"
using namespace std;

int main()
{
    StackOfInt stk(5);

    for (int i = 0; i < 10; ++i)
        stk.push(i*i);
    cout << stk << endl;
}

/* Output:
Growing array to 15 ...
{0,1,4,9,16,25,36,49,64,81}
*/

