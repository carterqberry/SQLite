// tstack4.cpp
#include <iostream>
#include "stack4.h"
using namespace std;

int main()
{
    StackOfInt stk;

    for (int i = 0; i < 5; ++i)
        stk.push(i*i);
    cout << "stk[2] == " << stk[2] << endl;
    cout << stk << endl;
}

/* Output:
stk[2] == 4
{0,1,4,9,16}
*/

