#include "datetime.h"
#include <cassert>
#include <cstdlib>

using namespace std;
using namespace DateStuff;

Time::Time(long y, int mo, int d, int h, int mi, int s)
{
    if (!isValidTime(y, mo, d, h, mi, s) ||
		(jd = gregToJul(y,mo,d,h,mi,s)) == 0.0)
	{
		throw DateError("Bad date in Time::Time(long y, "
                        "int mo, int d, int h, int mi, int s)");
	}
}

void Time::set(const std::string& s)
{
    jd = strToJul(s);
    if (jd == 0.0)
		throw DateError("Bad date string in "
                        "Time::set(string)");
}

void Time::set(const std::wstring& s)
{
    jd = wstrToJul(s);
    if (jd == 0.0)
		throw DateError("Bad date string in "
                        "Time::set(wstring)");
}

void DateStuff::Time::setYear(long new_y)
{
	long y;
	int mo, d, h, mi, s;
    get(y, mo, d, h, mi, s);
    if (!isValidDate(new_y, mo, d))
		throw DateError("Invalid date in Time::setYear");
    jd = gregToJul(new_y, mo, d, h, mi, s);
}

void DateStuff::Time::setMonth(int new_mo)
{
	long y;
	int mo, d, h, mi, s;
    get(y, mo, d, h, mi, s);
    if (!isValidDate(y, new_mo, d))
		throw DateError("Invalid date in Time::setYear");
    jd = gregToJul(y, new_mo, d, h, mi, s);
}

void DateStuff::Time::setDay(int new_d)
{
	long y;
    int mo, d, h, mi, s;
    get(y, mo, d, h, mi, s);
    if (!isValidDate(y, mo, new_d))
		throw DateError("Invalid date in Time::setYear");
    jd = gregToJul(y, mo, new_d, h, mi, s);
}

void DateStuff::Time::setHour(int new_h)
{
    if (new_h < 0 || new_h >= 24)
		throw DateError("Invalid hour in Time::setHour");
	long y;
    int mo, d, h, mi, s;
    get(y, mo, d, h, mi, s);
    jd = gregToJul(y, mo, d, new_h, mi, s);
}

void DateStuff::Time::setMinute(int new_mi)
{
    if (new_mi < 0 || new_mi >= 60)
		throw DateError("Invalid minute in Time::setMinute");
	long y;
    int mo, d, h, mi, s;
    get(y, mo, d, h, mi, s);
    jd = gregToJul(y, mo, d, h, new_mi, s);
}

void DateStuff::Time::setSecond(int new_s)
{
    if (new_s < 0 || new_s >= 60)
		throw DateError("Invalid second in Time::setMinute");
	long y;
    int mo, d, h, mi, s;
    get(y, mo, d, h, mi, s);
    jd = gregToJul(y, mo, d, h, mi, new_s);
}

void DateStuff::Time::set(long y, int mo, int d, int h,
                          int mi, int s)
{
    if (!isValidDate(y, mo, d))
		throw DateError("Invalid date in Time::set");
    if (h < 0 || h >= 24 || mi < 0 || mi >= 60 ||
        s < 0 || s >= 60)
		throw DateError("Invalid time in Time::set");
    jd = gregToJul(y, mo, d, h, mi, s);
}

long DateStuff::Time::weekDaysBetween(const Time& t) const
{
    Date d1(toDate());
    Date d2(t.toDate());
    return d1.weekDaysBetween(d2);
}

Duration DateStuff::Time::duration(const Time& t) const
{
	// Find order of two dates:
	double order = jd - t.jd;
	if (order == 0.0)
		return Duration(0,0,0);

    long y1, y2;
    int mo1, d1, h1, mi1, s1, mo2, d2, h2, mi2, s2;

    // Make the 1's precede the 2's so that we
    // get non-negative answers
	if (order > 0)
    {
        julToGreg(t.jd, y1, mo1, d1, h1, mi1, s1);
        julToGreg(jd, y2, mo2, d2, h2, mi2, s2);
    }
    else
    {
        julToGreg(jd, y1, mo1, d1, h1, mi1, s1);
        julToGreg(t.jd, y2, mo2, d2, h2, mi2, s2);
    }

    long years = y2 - y1;
	int months = mo2 - mo1;
	int days = d2 - d1;
    int hours = h2 - h1;
    int mins = mi2 - mi1;
    int secs = s2 - s1;
	assert(years > 0 ||
           years == 0 && months > 0 ||
		   years == 0 && months == 0 && days == 0
                      && hours > 0 ||
		   years == 0 && months == 0 && days == 0 && hours == 0
                      && mins > 0 ||
		   years == 0 && months == 0 && days == 0 && hours == 0
                      && mins == 0 && secs > 0);

    if (secs < 0)
    {
        --mins;
        secs += 60;
    }
    if (mins < 0)
    {
        --hours;
        mins += 60;
    }
    if (hours < 0)
    {
        --days;
        hours += 24;
    }

	int month2 = mo2;
	long year2 = y2;
	while (days < 0)
	{
		// Borrow from month:
		days += daysInPrevMonth(year2, month2--);
		--months;
		// This is a loop in case one is borrowing from
		// February, and therefore doesn't get enough days
		// to make 'days' go non-negative. This loop
		// will never iterate more than twice. It is not
		// necessary to decrement year2.
	}

	if (months < 0)
	{
		// Borrow from year:
		assert(years > 0);
		months += 12;
		--years;
	}
	return Duration(years,months,days,hours,mins,secs);
}

Time& DateStuff::Time::addDuration(const Duration& dur)
{
    if (dur.years != 0 || dur.months != 0)
    {
        long y;
        int mo, d, h, mi, s;
        julToGreg(jd, y, mo, d, h, mi, s);

        // Add years;
        y += dur.years;

        // Add months:
        if (dur.months != 0)
        {
            y += dur.months / 12;
            mo += dur.months % 12;
        }
        assert(-10 <= mo && mo <= 23);    // [1,12] + [-11, 11]

        // Correct months, if necessary
        if (mo > 12)
        {
            ++y;
            mo -= 12;
        }
        else if (mo <= 0)
        {
            --y;
            mo += 12;
        }

        // Make sure we didn't land on an invalid day:
		// e.g., 2/29 + 1 yr. -> 2/28, 3/31 + 1 mon. -> 4/30
        int eom = DateStuff::endOfMonth(y, mo);
        if (d > eom)
    	    d = eom;     // For leap change
        double newjd = gregToJul(y, mo, d, h, mi, s);
        if (newjd < DateStuff::min || newjd > DateStuff::max)
			throw DateError("Invalid date in "
                            "Time::addDuration");
        jd = newjd;
    }
    
    // Add days:
    double days = dur.days + dur.hours/24.0 + dur.mins/1440.0 +
                  dur.secs/86400.0;
    if (days != 0.0)
        addDays(days);
    return *this;
}

Time& DateStuff::Time::addWeekDays(long wd)
{
    long y;
    int mo, d, h, mi, s;
    get(y, mo, d, h, mi, s);
    Date temp(toDate());
    temp.addWeekDays(wd);
    temp.get(y, mo, d);
    jd = gregToJul(y, mo, d, h, mi, s);
    return *this;
}

