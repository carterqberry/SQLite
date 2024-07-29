// date.h

#ifndef DATE_H
#define DATE_H

#include <iosfwd>
#include <string>
#include <stdexcept>
#include <cassert>
#include "monthInfo.h"
#include "julianDate.h"
#include "duration.h"

namespace DateStuff
{

// Date exception class:
struct DateError : std::runtime_error
{
    DateError(const std::string& msg = "")
        : std::runtime_error(msg)
    {}
};

// Date class:
class Date
{
    friend class Time;

public:
    // Construction
    Date();     // today
    Date(const std::string& s);
    Date(const std::wstring& s);
    Date(long y, int m, int d);
    Date(long jd);

    // Conversion
    long toLong() const;
    std::string toString() const;
    std::wstring toWString() const;

    long getYear() const;
    int getMonth() const;
    int getDay() const;
    void get(long& y, int& m, int& d) const;

    void setYear(long y);
    void setMonth(int m);
    void setDay(int d);
    void set(long y, int m, int d);
    void set(const std::string& s);
    void set(const std::wstring& s);
    
    int dayOfYear() const;
    int dayOfWeek() const;

    bool isBetween(const Date& d1, const Date& d2) const;

    long daysBetween(const Date& d) const;
    long weekDaysBetween(const Date& d) const;
    Duration duration(const Date& d) const;

    Date& addDuration(const Duration& dur);
    Date& addDays(long d);
    Date& addWeekDays(long d);

    // Operators:
    friend long operator-(const Date& d1, const Date& d2)
    {
        return d1.jd - d2.jd;
    }
    
    friend bool operator==(const Date& d1, const Date& d2)
    {
        return d1.jd == d2.jd;
    }
    
    friend bool operator!=(const Date& d1, const Date& d2)
    {
        return d1.jd != d2.jd;
    }
    
    friend bool operator<(const Date& d1, const Date& d2)
    {
        return d1.jd < d2.jd;
    }
    
    friend bool operator<=(const Date& d1, const Date& d2)
    {
        return d1.jd <= d2.jd;
    }
    
    friend bool operator>(const Date& d1, const Date& d2)
    {
        return d1.jd > d2.jd;
    }
    
    friend bool operator>=(const Date& d1, const Date& d2)
    {
        return d1.jd >= d2.jd;
    }

    // The following compare function returns true if no swap
    // needs to be made to put to dates in order (a la STL).
    // If you want a strcmp-like function, use -daysBetween.
    friend bool compare(const Date& d1, const Date& d2)
    {
        return d1 <= d2;
    }

private:
    long jd;
};

// Date member inlines:
inline
Date::Date()
{
    jd = g2j();
}

inline
Date::Date(const std::string& s)
{
    set(s);
}

inline
Date::Date(const std::wstring& s)
{
    set(s);
}

inline
long Date::toLong() const
{
    return jd;
}

inline
std::string Date::toString() const
{
    return j2s(jd);
}

inline
std::wstring Date::toWString() const
{
    return j2ws(jd);
}

inline
long DateStuff::Date::getYear() const
{
    long y;
    int m, d;
    j2g(jd, y, m, d);
    return y;
}

inline
int DateStuff::Date::getMonth() const
{
    long y;
    int m, d;
    j2g(jd, y, m, d);
    return m;
}

inline
int DateStuff::Date::getDay() const
{
    long y;
    int m, d;
    j2g(jd, y, m, d);
    return d;
}

inline
void DateStuff::Date::get(long& y, int& m, int& d) const
{
    j2g(jd, y, m, d);
}

inline
int Date::dayOfWeek() const
{
    return dow(jd);
}

inline
bool Date::isBetween(const Date& d1, const Date& d2) const
{
    return d1.jd <= jd && jd <= d2.jd ||
           d2.jd <= jd && jd <= d1.jd;
}

inline
long Date::daysBetween(const Date& d) const
{
    return DateStuff::daysBetween(jd, d.jd);
}

inline
Date& Date::addDays(long d)
{
    jd = DateStuff::addDays(jd, d);
    return *this;
}

inline
Date::Date(long jd)
{
    using namespace std;
    assert(DateStuff::min <= jd && jd <= DateStuff::max);
    this->jd = jd;
}

}   // end namespace DateStuff

#endif

