#include <iostream>
#include "split.h"

int main()
{
    using namespace std;
    double frac;
    double x = 123.456;
    long whole = split(x, frac);
    cout << x << " = " << whole << " + " << frac << endl;
}

