#include "stack2.h"
#include <iostream>
#include <typeinfo>
using namespace std;

int main()
{
    try
    {
        Stack<int> s(5);
        for (int i = 0; i < 10; ++i)
            s.push(i);
    
        while (s.size() > 0)
            cout << s.pop() << ' ';
        cout << endl;

        // One pop too many:
        s.pop();
    }
    catch (exception& x)
    {
        cout << typeid(x).name() << ": "
             << x.what() << endl;
    }
}

