// datetest.cpp: Automated Testing (with a Framework)
#include <iostream>
#include <string>
#include "DateTest.h"
using namespace std;

int main()
{
    DateTest test;
    test.setStream(&cout);
    test.run();
    test.report();
}

/* Output:
Passed: 7, Failed: 0
*/

