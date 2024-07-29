#include "date.h"
#include <cassert>
#include <cstdlib>

using namespace std;
using namespace DateStuff;

DateStuff::Date::Date(long y, int m, int d)
{
    if (!isValidDate(y, m, d) ||
		(jd = g2j(y,m,d)) == 0)
	{
		throw DateError("Bad date in "
                        "Date::Date(long y, int m, int d)");
	}
}

void DateStuff::Date::set(const std::string& s)
{
    jd = s2j(s);
    if (jd == 0)
		throw DateError("Bad date string "
                        "in Date::set(string)");
}

void DateStuff::Date::set(const std::wstring& s)
{
    jd = ws2j(s);
    if (jd == 0)
		throw DateError("Bad date string in "
                        "Date::set(wstring)");
}

void DateStuff::Date::setYear(long new_y)
{
	long y;
	int m, d;
    get(y, m, d);
    if (!isValidDate(new_y, m, d) ||
		(jd = g2j(new_y, m, d)) == 0)
	{
		throw DateError("Invalid date in Date::setYear");
	}
}

void DateStuff::Date::setMonth(int new_m)
{
	long y;
	int m, d;
    get(y, m, d);
    if (!isValidDate(y, new_m, d) ||
		(jd = g2j(y, new_m, d)) == 0)
	{
		throw DateError("Invalid date in Date::setMonth");
	}
}

void DateStuff::Date::setDay(int new_d)
{
	long y;
	int m, d;
    get(y, m, d);
    if (!isValidDate(y, m, new_d) ||
		(jd = g2j(y, m, new_d)) == 0)
	{
		throw DateError("Invalid date in Date::setDay");
	}
}

void DateStuff::Date::set(long y, int m, int d)
{
    if (!isValidDate(y, m, d) ||
		(jd = g2j(y, m, d)) == 0)
	{
		throw DateError("Invalid date in Date::set");
	}
}

long DateStuff::Date::weekDaysBetween(const Date& d) const
{
	long jd1 = jd;
	long jd2 = d.jd;

	// NOTE: This algorithm assumes FRIDAY < SATURDAY < SUNDAY

	// Back-up to nearest weekday, if necessary:
	int dayno1 = dow(jd1);
	if (dayno1 > FRIDAY)
	{
		jd1 -= dayno1 - FRIDAY;
		dayno1 = FRIDAY;
	}
	int dayno2 = dow(jd2);
	if (dayno2 > FRIDAY)
	{
		jd2 -= dayno2 - FRIDAY;
		dayno2 = FRIDAY;
	}
	assert(dayno1 < SATURDAY && dayno2 < SATURDAY);

	long weeks = DateStuff::daysBetween(jd1, jd2) / 7L;
	int extra = dayno2 - dayno1;
	return weeks*5 + extra;
}

int DateStuff::Date::dayOfYear() const
{
    long y;
    int m, d;
	j2g(jd, y, m, d);
    return DateStuff::dayOfYear(y,m,d);
}

Duration DateStuff::Date::duration(const Date& d) const
{
	// Find order of two dates:
	int order = jd - d.jd;
	if (order == 0)
		return Duration(0,0,0);

    long y1, y2;
    int m1, d1, m2, d2;

    // Make the 1's precede the 2's so that we get
    // non-negative answers
	if (order > 0)
    {
        j2g(d.jd, y1, m1, d1);
        j2g(jd, y2, m2, d2);
    }
    else
    {
        j2g(jd, y1, m1, d1);
        j2g(d.jd, y2, m2, d2);
    }

    long years = y2 - y1;
	int months = m2 - m1;
	int days = d2 - d1;
	assert(years > 0 || years == 0 && months > 0 ||
		   years == 0 && months == 0 && days > 0);

	int month2 = m2;
	long year2 = y2;
	while (days < 0)
	{
		// Borrow from month:
		days += daysInPrevMonth(year2, month2--);
		--months;
		// This is a loop in case the previous month
		// doesn't have enough days to make 'days' go
		// non-negative. (Only happens if its February).
		// This loop will never iterate more than twice.
		// It is not necessary to decrement year2.
	}

	if (months < 0)
	{
		// Borrow from year:
		assert(years > 0);
		months += 12;
		--years;
	}
	assert(years >= 0 && months >= 0 && days >= 0);
	return Duration(years,months,days);
}

Date& DateStuff::Date::addDuration(const Duration& dur)
{
    if (dur.years != 0 || dur.months != 0)
    {
        long y;
        int m, d;
        j2g(jd, y, m, d);

        // Add years;
        y += dur.years;

        // Add months:
        if (dur.months != 0)
        {
            y += dur.months / 12;
            m += dur.months % 12;
        }
        assert(-10 <= m && m <= 23);    // [1,12] + [-11, 11]

        // Correct months, if necessary
        if (m > 12)
        {
            ++y;
            m -= 12;
        }
        else if (m <= 0)
        {
            --y;
            m += 12;
        }

        // Make sure we didn't land on an invalid day:
		// e.g., 2/29 + 1 yr. -> 2/28, 3/31 + 1 mon. -> 4/30
        int eom = endOfMonth(y,m);
        if (d > eom)
    	    d = eom;     // For leap change
        long newjd = g2j(y, m, d);
        if (newjd < DateStuff::min || newjd > DateStuff::max)
			throw DateError("Invalid date in "
                            "Date::addDuration");
        jd = newjd;
    }
    
    // Add days:
    if (dur.days != 0)
        addDays(dur.days);
    return *this;
}

// Can this be optimized? This is a tricky algorithm.
Date& DateStuff::Date::addWeekDays(long wd)
{
    if (wd != 0)
    {
        bool negative = wd < 0;
    	int dayno = dayOfWeek();
    
        // If weekend, backup to FRIDAY (if !negative)
		// or advance to MONDAY (if negative). This is
		// to find the correct weekday to start from.
    	if (dayno > FRIDAY)
    	{
    		addDays(negative ? 7 - dayno : FRIDAY - dayno);
    		dayno = negative ? MONDAY : FRIDAY;
    	}
    
    	// Advance by weeks first:
    	if (abs(wd) >= 5)
        {
            long weeks = wd / 5;
            addDays(weeks * 7);
        }
    
    	// Now advance the rest of the days:
    	int extra = abs(static_cast<int>(wd % 5));
    	if (negative && dayno - extra < MONDAY ||
           !negative && dayno + extra > FRIDAY)
    		extra += 2;	// Skip weekend
    	if (extra > 0)
    		addDays(negative ? -extra : extra);
    }
    return *this;
}
