// julianDate.h: Basic Julian Day functions

// This header only provides whole day functions
// (no fractions allowed)

#ifndef JULIANDATE_H
#define JULIANDATE_H

#include <string>
#include <cstdio>
#include <cstdlib>
#include <cwchar>

namespace DateStuff
{

// Useful constants:
enum Days {MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY,
           SATURDAY, SUNDAY};
enum Months {MONTH_ERROR, JANUARY, FEBRUARY, MARCH, APRIL, MAY,
             JUNE, JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER,
             DECEMBER};

const double daysPerYear = 365.0 + 97.0/400.0;
const long min = 2299161;       // 1582-10-15
const long max = 536800999;     // 1,464,999-02-11

    // Julian-Gregorian Conversions:

// The following are defined in julianDate.cpp:
long g2j(long year, int month, int day);
long g2j();
void j2g(long jday, long& year, int& month, int& day);
std::string j2s(double jd);
std::wstring j2ws(double jd);
long s2j(const std::string& s);
long ws2j(const std::wstring& s);

// Inlines begin here:

// Day of Week:
inline
int dow(long jd)
{
    return jd % 7;
}

// The following compare function returns true if no swap
// needs to be made to put to dates in order (a la STL).
// If you want a strcmp-like function just subtract the two
// julian numbers (e.g., jd1 - jd2).
inline
bool compare(long jd1, long jd2)
{
    return jd1 <= jd2;
}

inline
long daysBetween(long jd1, long jd2)
{
    return jd2 - jd1;
}

inline
double yearsBetween(long jd1, long jd2)
{
    // This is just an approximation. It's not so bad
    // for large durations, but if you want exact
    // years/months/days, use the Date class.
    return (jd2 - jd1) / daysPerYear;
}

inline
long addDays(long jd, long d)
{
    return jd + d;
}

inline
double addYears(long jd, long y)
{
    // This is just an approximation. It's not so bad
    // for large durations, but if you want exact
    // years/months/days, use the Date class.
    return jd + y*daysPerYear;
}

}   // end namespace DateStuff

#endif

