#include "test.h"
#include "date.h"

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
        test_(mybday < today);
        test_(mybday <= today);
        test_(mybday != today);
        test_(mybday == mybday);
    }
    void testDuration()
    {
        Duration dur = duration(mybday, today);
        test_(dur.years == 49);
        test_(dur.months == 10);
        test_(dur.days == 3);
    }
};
