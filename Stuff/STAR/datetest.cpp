// datetest.cpp: Automated Testing (w/o a Framework)
#include <iostream>
#include <string>
#include "date.h"
using namespace std;

#define test(cond) doTest(#cond, cond)

int nPass = 0;
int nFail = 0;

void doTest(const string& txt, bool cond)
{
    if (!cond)
    {
        cout << txt << " failed\n";
        ++nFail;
    }
    else
        ++nPass;
}

int main()
{
    Date mybday(1951,10,1);
    Date today;

    test(mybday < today);
    test(mybday <= today);
    test(mybday != today);
    test(mybday == mybday);

    Date mywed(1975,5,10);
    Duration dur = duration(mywed, mybday);
    test(dur.years == 23);
    test(dur.months == 7);
    test(dur.days == 9);

    cout << "Passed: " << nPass << ", Failed: "
         << nFail << endl;
    
}

/* Output:
Passed: 7, Failed: 0
*/

