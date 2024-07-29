// JulianDateTest.h

#ifndef JULIANDATETEST_H
#define JULIANDATETEST_H

#include "test.h"
#include "julianDate.h"
#include <ctime>

using namespace DateStuff;

class JulianDateTest : public Test
{
    long d1, d2, d3;

public:
    JulianDateTest()
    {
        d1 = 2438762;        // 1965-1-1, a Friday
        d2 = 2451545;        // 2000-1-1, a Saturday(5)
        d3 = 2451605;        // 2000-3-1, a Wednesday
    }
    void run()
    {
        testConversions();
        testLimits();
        testDayOfWeek();
        testStrings();
        testCompare();
        testArithmetic();
        testToday();
    }
    void testConversions()
    {
        _test(d1 == g2j(1965,1,1));
        _test(d2 == g2j(2000,1,1));
        _test(d3 == g2j(2000,3,1));
        long y;
        int m, d;
        j2g(d1, y, m, d);
        _test(y == 1965 && m == 1 && d == 1);
        j2g(d2, y, m, d);
        _test(y == 2000 && m == 1 && d == 1);
    }
    void testLimits()
    {
        _test(DateStuff::max == 536800999);
        _test(g2j(1464999L, 2, 11) == DateStuff::max);
        _test(g2j(1464999L, 2, 12) == 0);
        long y;
        int m, d;
        j2g(DateStuff::max, y, m, d);
        _test(y == 1464999L);
        _test(m == 2);
        _test(d == 11);

        _test(DateStuff::min == 2299161);
        _test(g2j(1582, 10, 15) == DateStuff::min);
        _test(g2j(1582, 10, 14) == 0);
        j2g(DateStuff::min, y, m, d);
        _test(y == 1582);
        _test(m == 10);
        _test(d == 15);
    }
    void testDayOfWeek()
    {
        _test(dow(d1) == FRIDAY);
        _test(dow(d2) == SATURDAY);
        _test(dow(d3) == WEDNESDAY);
    }
    void testStrings()
    {
        using namespace std;
        string s = "1965-01-01";
        wstring w = L"1965-01-01";
        _test(j2s(d1) == s);
        _test(j2ws(d1) == w);
        _test(s2j(s) == d1);
        _test(ws2j(w) == d1);
    }
    void testCompare()
    {
        _test(compare(d1, d2));
        _test(!compare(d2, d1));
        _test(compare(d1, d1));
    }
    void testArithmetic()
    {
        _test(daysBetween(g2j(1996,2,1),g2j(1996,3,1)) == 29);
        _test(daysBetween(g2j(1995,2,1),g2j(1995,3,1)) == 28);
        _test(daysBetween(g2j(1996,3,1),g2j(1996,2,1)) == -29);
        _test(daysBetween(g2j(1995,3,1),g2j(1995,2,1)) == -28);
        _test(addDays(d1,5) == d1 + 5);
        _test(addDays(d1,-5) == d1 - 5);
        _test(yearsBetween(d1, d2) ==
             daysBetween(d1, d2)/daysPerYear);
        _test(addYears(d1, 5) == d1 + 5*daysPerYear);
    }
    void testToday()
    {
        using namespace std;
        long today = g2j();
        time_t tval = time(0);
        long y;
        int m, d;
        j2g(today, y, m, d);
        struct tm* fields = localtime(&tval);
        _test(fields->tm_year+1900 == y &&
             fields->tm_mon + 1 == m &&
             fields->tm_mday == d);
    }
};

#endif
