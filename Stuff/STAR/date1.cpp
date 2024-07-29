#include <iostream>
#include "date.h"
using namespace std;

int main()
{
   Date today;
   cout << "Today is " << today.toString() << '\n';

   Date mybday(1951,10,1);
   Duration dur = duration(today, mybday);
   cout << "Today I am " << dur.years
        << " years, " << dur.months
        << " months, and " << dur.days
        << " days old\n";
}

/* Output:
Today is 2001-8-11
Today I am 49 years, 10 months, and 10 days old
*/

