// julianTime.h: Basic Julian Day functions

// This version keeps the full fraction of a day.

#ifndef JULIANTIME_H
#define JULIANTIME_H

#include "julianDate.h"

namespace DateStuff
{

// The following are defined in julianTime.cpp:
double  gregToJul();
void julToGreg(double jday, long& year, int& month, int& day,
               int& hour, int& minute, int& second);
double gregToJul(long year, int month, int day,
                 int hrs = 12, int min = 0, int sec = 0);
std::string julToStr(double jd);
std::wstring julToWStr(double jd);
double strToJul(const std::string& str);
double wstrToJul(const std::wstring& str);

// Inlines begin here:

// Day of Week functions:
inline
int dow(double jd)
{
    return static_cast<long>(jd + 0.5) % 7;
}

// The following compare function returns true if no swap
// needs to be made to put to dates in order (a la STL).
// If you want a strcmp-like function just subtract the two
// julian numbers (e.g., jd1 - jd2).
inline
bool compare(double jd1, double jd2)
{
    return jd1 <= jd2;
}

inline
double daysBetween(double jd1, double jd2)
{
    return jd2 - jd1;
}

inline
double yearsBetween(double jd1, double jd2)
{
    // This is just an approximation. It's not so bad
    // for large durations, but if you want exact
    // years/months/days, use the Date class.
    return (jd2 - jd1) / daysPerYear;
}

inline
double addDays(double jd, double d)
{
    return jd + d;
}

inline
double addYears(double jd, double y)
{
    // This is just an approximation. It's not so bad
    // for large durations, but if you want exact
    // years/months/days, use the Date class.
    return jd + y*daysPerYear;
}

}   // end namespace DateStuff

#endif

