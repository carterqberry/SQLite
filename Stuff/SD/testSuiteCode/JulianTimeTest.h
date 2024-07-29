// JulianTimeTest.h

#ifndef JULIANTIMETEST_H
#define JULIANTIMETEST_H

#include "test.h"
#include "julianTime.h"
#include "mathstuff.h"

using namespace DateStuff;

class JulianTimeTest : public Test
{
    double t1, t2, t3, t4;
public:
    JulianTimeTest()
    {
        t1 = 2438762.0;        // 1965-1-1
        t2 = 2451545.0;        // 2000-1-1, a Saturday(5)
        t3 = 2450299.026389;// 1996-08-03 12:38:00
        t4 = 2451361.113796;// 1999-07-01 14:43:52
    }
    void run()
    {
        testConversions();
        testDayOfWeek();
        testStrings();
        testCompare();
        testArithmetic();
        testToday();
    }
    void testConversions()
    {
        _test(t1 == gregToJul(1965,1,1));
        _test(t2 == gregToJul(2000,1,1));
        _test(t3 == round(gregToJul(1996,8,3,12,38), 6));
        _test(t4 == round(gregToJul(1999,7,1,14,43,52), 6));
        long y;
        int mo, d, h, mi, s;
        julToGreg(t1, y, mo, d, h, mi, s);
        _test(y == 1965 && mo == 1 && d == 1 && h == 12 &&
             mi == 0 && s == 0);
        julToGreg(t2, y, mo, d, h, mi, s);
        _test(y == 2000 && mo == 1 && d == 1 && h == 12 &&
             mi == 0 && s == 0);
        julToGreg(t3, y, mo, d, h, mi, s);
        _test(y == 1996 && mo == 8 && d == 3 && h == 12 &&
             mi == 38 && s == 0);
        julToGreg(t4, y, mo, d, h, mi, s);
        _test(y == 1999 && mo == 7 && d == 1 && h == 14 &&
             mi == 43 && s == 52);
    }
    void testDayOfWeek()
    {
        _test(dow(t1) == FRIDAY);
        _test(dow(t2) == SATURDAY);
        _test(dow(t3) == SATURDAY);
        _test(dow(t4) == THURSDAY);
    }
    void testStrings()
    {
        using namespace std;
        string s = "1965-01-01 12:00:00";
        wstring w = L"1965-01-01 12:00:00";
        _test(julToStr(t1) == s);
        _test(julToWStr(t1) == w);
        _test(strToJul(s) == t1);
        _test(wstrToJul(w) == t1);
    }
    void testCompare()
    {
        _test(compare(t1, t2));
        _test(!compare(t2, t1));
        _test(compare(t1, t1));
    }
    void testArithmetic()
    {
        _test(daysBetween(t1, t2) == t2 - t1);
        _test(daysBetween(gregToJul(1996,2,1),
                         gregToJul(1996,3,1)) == 29.0);
        _test(daysBetween(gregToJul(1995,2,1),
                         gregToJul(1995,3,1)) == 28.0);
        _test(daysBetween(gregToJul(1996,3,1),
                         gregToJul(1996,2,1)) == -29.0);
        _test(daysBetween(gregToJul(1995,3,1),
                         gregToJul(1995,2,1)) == -28.0);
        _test(daysBetween(t1, gregToJul(1965,1,2,18)) == 1.25);
        _test(addDays(t1,5) == t1 + 5);
        _test(addDays(t1,-5) == t1 - 5);
        _test(yearsBetween(t1, t2) ==
             daysBetween(t1, t2)/DateStuff::daysPerYear);
    }
    void testToday()
    {
        using namespace std;
        double today = gregToJul();
        time_t tval = time(0);
        long y;
        int mo, d, h, mi, s;
        julToGreg(today, y, mo, d, h, mi, s);
        struct tm* fields = localtime(&tval);
        _test(fields->tm_year+1900 == y &&
             fields->tm_mon + 1 == mo &&
             fields->tm_mday == d &&
             fields->tm_hour == h &&
             fields->tm_min == mi &&
             fields->tm_sec == s);
        // There is a miniscule chance the seconds might be
        // wrong, depending on how slow the machine is.
    }
};

#endif
