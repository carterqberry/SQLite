// datetest.cpp: Automated Testing (w/o a Framework)
#include <iostream>
#include <string>
#include "date.h"
using namespace std;
using namespace DateStuff;

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

    Duration dur = mybday.duration(today);
    test(dur.years == 49);
    test(dur.months == 6);
    test(dur.days == 11);

    cout << "Passed: " << nPass << ", Failed: "
         << nFail << endl;
    
}

/* Output:
Passed: 7, Failed: 0
*/

