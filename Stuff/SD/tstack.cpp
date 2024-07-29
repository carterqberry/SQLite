#include "stack.h"
#include <iostream>
using namespace std;

int main()
{
    Stack<int> s(5);
    for (int i = 0; i < 10; ++i)
        s.push(i);

    while (s.size() > 0)
        cout << s.pop() << ' ';
}

