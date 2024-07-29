// monthInfo.h

#ifndef MONTH_STATS
#define MONTH_STATS

#include <cassert>

namespace DateStuff
{

extern const int daysInMonth[2][13];
extern const int daysToDate[2][13];

int     daysInPrevMonth(long y, int m);

inline
bool    isLeap(long y)
{
    // Determines if year is a leap year
    return y % 4 == 0 && y % 100 != 0 || y % 400 == 0;
}

inline
int     endOfMonth(long y, int m)
{
	assert(1 <= m && m <= 12);
	return daysInMonth[isLeap(y)][m];
}

inline
int     dayOfYear(long y, int m, int d)
{
	assert(1 <= m && m <= 12);
    return daysToDate[isLeap(y)][m-1] + d;
}

inline
bool    isValidDate(long y, int m, int d)
{
	return (1582 < y && y < 1464999 ||
		    y == 1582 && (m > 10 || m == 10 && d >= 15) ||
			y == 1464999 && (m < 2 || m == 2 && d <= 11)
		   ) &&
		   1 <= m && m <= 12 &&
		   1 <= d && d <= endOfMonth(y,m);
}

}   // end namespace DateStuff

#endif

