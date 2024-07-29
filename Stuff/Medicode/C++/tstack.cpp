// tstack5.cpp
#include <iostream>
#include "stack5.h"
using namespace std;

int main()
{
    StackOfInt stk;

    for (int i = 0; i < 5; ++i)
        stk.push(i*i);
    while (stk.size() > 0)
        cout << stk.pop()) << endl;
}
