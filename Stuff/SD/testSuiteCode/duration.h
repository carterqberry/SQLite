#ifndef DURATION_H
#define DURATION_H

namespace DateStuff
{

struct Duration
{
    long years;
    signed char months;
    signed char days;
    signed char hours;
    signed char mins;
    signed char secs;
    Duration(long y = 0, int mo = 0, int d = 0,
             int h = 0, int mi = 0, int s = 0)
    {
        years = y;
        months = static_cast<char>(mo);
        days = static_cast<char>(d);
        hours = static_cast<char>(h);
        mins = static_cast<char>(mi);
        secs = static_cast<char>(s);
    }
	Duration operator-() const
	{
		return Duration(-years, -months, -days,
				        -hours, -mins, -secs);
	}
};

inline bool operator==(const Duration& d1,
		               const Duration& d2)
{
	return d1.years == d2.years &&
		   d1.months == d2.months &&
		   d1.days == d2.days &&
		   d1.hours == d2.hours &&
		   d1.mins == d2.mins &&
		   d1.secs == d2.secs;
}

inline bool operator!=(const Duration& d1,
		               const Duration& d2)
{
	return !operator==(d1, d2);
}

}	// end namespace DateStuff

#endif

