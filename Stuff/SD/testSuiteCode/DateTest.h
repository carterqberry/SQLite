#include "test.h"
#include "date.h"

using DateStuff::Date;

class DateTest : public Test
{
    Date mybday;
    Date today;

public:
    DateTest()
        : mybday(1951, 10,1)
    {}
    void run()
    {
        testOps();
        testDuration();
    }
    void testOps()
    {
        _test(mybday < today);
        _test(mybday <= today);
        _test(mybday != today);
        _test(mybday == mybday);
    }
    void testDuration()
    {
        DateStuff::Duration dur = mybday.duration(today);
        _test(dur.years == 49);
        _test(dur.months == 6);
        _test(dur.days == 11);
    }
};
