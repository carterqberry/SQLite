// time.h

#ifndef DATETIME_H
#define DATETIME_H

#include "date.h"
#include "julianTime.h"
#include "mathstuff.h"

namespace DateStuff
{
                                
// Time class:
class Time
{
public:
    // Construction
    Time();     // today
    Time(const std::string& s);
    Time(const std::wstring& s);
    Time(long y, int mo, int d, int h = 12, int mi = 0,
         int s = 0);
	Time(double jd);
    Time(const Date& d);

    // Conversions
    std::string toString() const;
    std::wstring toWString() const;
    Date toDate() const;
	double toDouble() const;

    long getYear() const;
    int getMonth() const;
    int getDay() const;
    int getHour() const;
    int getMinute() const;
    int getSecond() const;
    void get(long& y, int& mo, int& d, int& h, int& mi,
             int& s) const;

    void setYear(long y);
    void setMonth(int mo);
    void setDay(int d);
    void setHour(int h);
    void setMinute(int mi);
    void setSecond(int s);
    void set(long y, int m, int d, int h = 12, int mi = 0,
             int s = 0);
    void set(const std::string& s);
    void set(const std::wstring& s);
    
    int dayOfYear() const;
    int dayOfWeek() const;

    bool isBetween(const Time& d1, const Time& d2) const;

    double daysBetween(const Time& d) const;
    long weekDaysBetween(const Time& d) const;  // use Date
    Duration duration(const Time& d) const;     // use Date?

    Time& addDuration(const Duration& dur);
    Time& addDays(double d);
    Time& addWeekDays(long d);

    // Operators:
    friend double operator-(const Time& d1, const Time& d2)
    {
        return d1.jd - d2.jd;
    }
    
    friend bool operator==(const Time& d1, const Time& d2)
    {
        // Round to 2 decimals (a little better than nearest
        // second)
        double jd1 = round(d1.jd, 2);
        double jd2 = round(d2.jd, 2);
        return jd1 == jd2;
    }
    
    friend bool operator!=(const Time& d1, const Time& d2)
    {
        return !operator==(d1, d2);
    }
    
    friend bool operator<(const Time& d1, const Time& d2)
    {
        return d1.jd < d2.jd;
    }
    
    friend bool operator<=(const Time& d1, const Time& d2)
    {
        return d1.jd <= d2.jd;
    }
    
    friend bool operator>(const Time& d1, const Time& d2)
    {
        return d1.jd > d2.jd;
    }
    
    friend bool operator>=(const Time& d1, const Time& d2)
    {
        return d1.jd >= d2.jd;
    }

	// The following compare function returns true if no swap
	// needs to be made to put to times in order (a la STL).
	// If you want a strcmp-like function, use operator-.
    friend bool compare(const Time& d1, const Time& d2)
    {
        return d1 <= d2;
    }

private:
    double jd;
};

// Non-member inline:
inline bool isValidTime(long y, int mo, int d, int h, int mi,
                        int s)
{
    return isValidDate(y, mo, d) && 0 <= h && h < 24
                                && 0 <= mi && mi < 60
                                && 0 <= s && s < 60;
}

// Time member inlines:
inline
Time::Time()
{
    jd = gregToJul();
}

inline
Time::Time(const std::string& s)
{
    set(s);
}

inline
Time::Time(const std::wstring& s)
{
    set(s);
}

inline
Time::Time(double jd)
{
	this->jd = jd;
}

inline
Time::Time(const Date& d)
{
    jd = d.jd;
}

inline
std::string Time::toString() const
{
    return julToStr(jd);
}

inline
std::wstring Time::toWString() const
{
    return julToWStr(jd);
}

inline
Date Time::toDate() const
{
    return Date(static_cast<long>(jd + 0.5));
}

inline
double Time::toDouble() const
{
	return jd;
}

inline
long Time::getYear() const
{
    long y;
    int m, d;
    j2g(static_cast<long>(jd + 0.5), y, m, d);
    return y;
}

inline
int Time::getMonth() const
{
    long y;
    int m, d;
    j2g(static_cast<long>(jd + 0.5), y, m, d);
    return m;
}

inline
int Time::getDay() const
{
    long y;
    int m, d;
    j2g(static_cast<long>(jd + 0.5), y, m, d);
    return d;
}

inline
int DateStuff::Time::getHour() const
{
    long y;
    int mo, d, h, mi, s;
    julToGreg(jd, y, mo, d, h, mi, s);
    return h;
}

inline
int DateStuff::Time::getMinute() const
{
    long y;
    int mo, d, h, mi, s;
    julToGreg(jd, y, mo, d, h, mi, s);
    return mi;
}

inline
int DateStuff::Time::getSecond() const
{
    long y;
    int mo, d, h, mi, s;
    julToGreg(jd, y, mo, d, h, mi, s);
    return s;
}

inline
void DateStuff::Time::get(long& y, int& mo, int& d, int& h,
                          int& mi, int& s) const
{
    julToGreg(jd, y, mo, d, h, mi, s);
}

inline
int Time::dayOfWeek() const
{
    return dow(jd);
}

inline
bool Time::isBetween(const Time& d1, const Time& d2) const
{
    return d1.jd <= jd && jd <= d2.jd ||
		   d2.jd <= jd && jd <= d1.jd;
}

inline
double Time::daysBetween(const Time& d) const
{
    return DateStuff::daysBetween(jd, d.jd);
}

inline
Time& Time::addDays(double d)
{
    jd = DateStuff::addDays(jd, d);
    return *this;
}

inline
int Time::dayOfYear() const
{
	return toDate().dayOfYear();
}

}   // DateStuff

#endif

