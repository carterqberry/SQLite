#include <iostream>
#include "suite.h"
#include "JulianDateTest.h"
#include "JulianTimeTest.h"
#include "MonthInfoTest.h"
#include "DateTest.h"
#include "TimeTest.h"
using namespace std;

int main()
{
    Suite s("Date and Time Tests", &cout);

    s.addTest(new MonthInfoTest);
    s.addTest(new JulianDateTest);
    s.addTest(new JulianTimeTest);
    s.addTest(new DateTest);
    s.addTest(new TimeTest);
    s.run();
    long nFail = s.report();
    s.free();
    cout << "\nTotal failures: " << nFail << endl;
    return nFail;
}

