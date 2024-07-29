// TimeTest.h

#ifndef TIMETEST_H
#define TIMETEST_H

#include <ctime>
#include "test.h"
#include "datetime.h"

using namespace DateStuff;

class TimeTest : public Test
{
	const Time y2k, bd, leap;

public:
	TimeTest()
		: y2k(2000,1,1,18), bd(1951,10,1,5,30), leap(1996,2,29)
	{}
	void run()
	{
		testConstructors();
		testToday();
		testConversions();
		testGets();
		testSets();
		testDayOf();
		testBetween();
		testArithmetic();
		testCompare();
	}
	void testConstructors();
	void testToday()
	{
		using namespace std;
		Time today;
		time_t tval = time(0);
		struct tm* fields = localtime(&tval);
		_test(fields->tm_year+1900 == today.getYear() &&
			 fields->tm_mon + 1 == today.getMonth() &&
			 fields->tm_mday == today.getDay() &&
			 fields->tm_hour == today.getHour() &&
			 fields->tm_min == today.getMinute() &&
			 fields->tm_sec	== today.getSecond());
	}
	void testConversions()
	{
		_test(y2k.toDouble() == 2451545.25);
		_test(y2k.toString() == "2000-01-01 18:00:00");
		_test(y2k.toWString() == L"2000-01-01 18:00:00");
		_test(round(bd.toDouble(), 3) == round(2433920.7291667, 3));
		_test(bd.toString() == "1951-10-01 05:30:00");
		_test(bd.toWString() == L"1951-10-01 05:30:00");
		Date d(bd.toDate());
		_test(d.getYear() == bd.getYear() &&
			 d.getMonth() == bd.getMonth() &&
			 d.getDay() == bd.getDay());
	}
	void testGets()
	{
		_test(y2k.getYear() == 2000);
		_test(y2k.getMonth() == 1);
		_test(y2k.getDay() == 1);
		_test(y2k.getHour() == 18);
		_test(y2k.getMinute() == 0);
		_test(y2k.getSecond() == 0);
		long y;
		int mo, d, h, mi, s;
		y2k.get(y,mo,d,h,mi,s);
		_test(y == y2k.getYear() && mo == y2k.getMonth() &&
			 d == y2k.getDay() && h == y2k.getHour() &&
			 mo == y2k.getMonth() && s == y2k.getSecond());
	}
	void testSets();
	void testDayOf()
	{
		_test(y2k.dayOfWeek() == SATURDAY);
		_test(Time(1976,8,13).dayOfWeek() == FRIDAY);
		_test(y2k.dayOfYear() == 1);
		_test(leap.dayOfYear() == 60);
		Time d1(1996,3,1);
		_test(d1.dayOfYear() == 61);
		d1.set(1997,3,1);
		_test(d1.dayOfYear() == 60);
	}
	void testBetween()
	{
		_test(leap.isBetween(bd, y2k));
		_test(leap.isBetween(y2k, bd));
		_test(leap.isBetween(leap, leap));
		_test(!bd.isBetween(leap, y2k));
		_test(!bd.isBetween(y2k, leap));
		_test(!y2k.isBetween(bd, leap));
		_test(!y2k.isBetween(leap, bd));

		Time d1(1999,7,16);		// FRIDAY
		Time d2(1999,8,13,18);	// 4 weeks later
		_test(d1.daysBetween(d2) == 4*7 + 0.25);
		_test(d2.daysBetween(d1) == -4*7 - 0.25);
		_test(d1.weekDaysBetween(d2) == 4*5);
		_test(d2.weekDaysBetween(d1) == -4*5);

		Time d3(1996,2,28);
		Time d4(1996,3,1);
		_test(d3.daysBetween(d4) == 2);
		d3.set(1997,2,28);
		d4.set(1997,3,1);
		_test(d3.daysBetween(d4) == 1);

		_test(d1.daysBetween(d2) == d2 - d1);

		Duration dur = bd.duration(y2k);
		_test(dur.years == 48 && dur.months == 3 &&
			 dur.days == 0 && dur.hours == 12 &&
			 dur.mins == 30 && dur.secs == 0);
		_test(dur == y2k.duration(bd));

		dur = leap.duration(y2k);
		_test(dur.years == 3 && dur.months == 10 &&
			 dur.days == 3 && dur.hours == 6
			 && dur.mins == 0 && dur.secs == 0);
	}
	void testArithmetic()
	{
		Time bd2(bd);
		Duration dur(47,9,18,10,48,22);
		bd2.addDuration(dur);
		_test(bd2.getYear() == 1999 &&
			 bd2.getMonth() == 7 &&
			 bd2.getDay() == 19 &&
			 bd2.getHour() == 16 &&
			 bd2.getMinute() == 18 &&
			 bd2.getSecond() == 22);
		
		Time bd3(bd);
//		Duration dur2(47, 10, -13, 10, 48, 22);	// variation
		Duration dur2(47, 9, 19, -13, -12, 22);
		bd3.addDuration(dur2);
		_test(bd2 == bd3);

		Time d1(1999,7,16);		// FRIDAY
		d1.addDays(4*7);
		Time d2(1999,8,13);		// 4 weeks later
		_test(d1 == d2);
		_test(d1 - d2 == 0.0);
		d1.addDays(-4*7);
		_test(d1 - d2 == -4*7);
		d1.addWeekDays(4*5);
		_test(d1 == d2);
	}
	void testCompare()
	{
		Time bd2(bd);
		_test(bd == bd2);
		_test(bd2 == bd);
		_test(y2k != bd);
		_test(bd != y2k);
		_test(y2k > bd);
		_test(y2k >= bd);
		_test(bd < y2k);
		_test(bd <= y2k);
		_test(compare(bd, y2k));
		_test(!compare(y2k, bd));
	}
};

#endif
