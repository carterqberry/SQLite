// monthInfo.cpp

#include "monthInfo.h"
    
const int DateStuff::daysInMonth[2][13] =
{
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

const int DateStuff::daysToDate[2][13] =
{
    {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304,
        334, 365}, 
    {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305,
        335, 366}
};

int DateStuff::daysInPrevMonth(long y, int m)
{
	assert(1 <= m && m <= 12);
    if (m == 1)
    {
        --y;
        m = 12;
    }
    else
        --m;
    return daysInMonth[isLeap(y)][m];
}

