#include "TimeTest.h"

void TimeTest::testConstructors()
{
	_test(y2k.getYear() == 2000 && y2k.getMonth() == 1 &&
		  y2k.getDay() == 1);

	// Catch invalid year
	try
	{
		Time t(1582,1,1);
		_fail("Time(0,1,1)");
	}
	catch (DateError&)
	{
		_succeed();
	}
	try
	{
		Time t(1500000L,1,1);
		_fail("Date(1500000L,1,1)");
	}
	catch (DateError&)
	{
		_succeed();
	}

	// Catch invalid month
	try
	{
		Time t(1997,0,1);
		_fail("Time(1997,0,1)");
	}
	catch (DateError&)
	{
		_succeed();
	}
	try
	{
		Time t(1997,13,1);
		_fail("Time(1997,13,1)");
	}
	catch (DateError&)
	{
		_succeed();
	}

	// Catch invalid day
	try
	{
		Time t(1997,2,0);
		_fail("Time(1997,2,29)");
	}
	catch (DateError&)
	{
		_succeed();
	}
	try
	{
		Time t(1997,2,29);
		_fail("Time(1997,2,29)");
	}
	catch (DateError&)
	{
		_succeed();
	}

	// Catch invalid hour
	try
	{
		Time t(1997,2,28,25,0,0);
		_fail("Time(1997,2,28,25,0,0)");
	}
	catch (DateError&)
	{
		_succeed();
	}
	try
	{
		Time t(1997,2,28,-1,0,0);
		_fail("Time(1997,2,28,-1,0,0)");
	}
	catch (DateError&)
	{
		_succeed();
	}

	// Catch invalid minute
	try
	{
		Time t(1997,2,28,0,61,0);
		_fail("Time(1997,2,28,0,61,0)");
	}
	catch (DateError&)
	{
		_succeed();
	}
	try
	{
		Time t(1997,2,28,0,-1,0);
		_fail("Time(1997,2,28,0,-1,0)");
	}
	catch (DateError&)
	{
		_succeed();
	}

	// Catch invalid second
	try
	{
		Time t(1997,2,28,0,0,61);
		_fail("Time(1997,2,28,0,0,61)");
	}
	catch (DateError&)
	{
		_succeed();
	}
	try
	{
		Time t(1997,2,28,0,0,61);
		_fail("Time(1997,2,28,0,0,61)");
	}
	catch (DateError&)
	{
		_succeed();
	}

	// Date Constructor:
	Date d(1951,10,1);
	Time t(d);
	_test(t.getYear() == d.getYear() && t.getMonth() == d.getMonth() &&
		  t.getDay() == d.getDay() && t.getHour() == 12 &&
		  t.getMinute() == 0 && t.getSecond() == 0);

	// String constructors:
	Time d1("1951-10-01 5:30:10");
	_test(d1.getYear() == 1951 && d1.getMonth() == 10 &&
		  d1.getDay() == 1 && d1.getHour() == 5 &&
		  d1.getMinute() == 30 && d1.getSecond() == 10);
	Time d2(L"1951-10-01 5:30:10");
	_test(d2.getYear() == 1951 && d2.getMonth() == 10 &&
		  d2.getDay() == 1 && d2.getHour() == 5 &&
		  d2.getMinute() == 30 && d2.getSecond() == 10);

	// Julian day ctor:
	Time dj(DateStuff::min);
	_test(dj.getYear() == 1582 && dj.getMonth() == 10 &&
		  dj.getDay() == 15 && dj.getHour() == 12 &&
		  dj.getMinute() == 0 && dj.getSecond() == 0);
}

void TimeTest::testSets()
{
	Time bd2(bd);

	bd2.setYear(1999);
	_test(bd2.getYear() == 1999);
	bd2.setMonth(7);
	_test(bd2.getMonth() == 7);
	bd2.setDay(19);
	_test(bd2.getDay() == 19);
	bd2.setHour(16);
	_test(bd2.getHour() == 16);
	bd2.setMinute(18);
	_test(bd2.getMinute() == 18);
	bd2.setSecond(22);
	_test(bd2.getSecond() == 22);

	bd2.set(1951,10,1,5,30);
	_test(bd2.getYear() == 1951 && bd2.getMonth() == 10 &&
		  bd2.getDay() == 1 && bd2.getHour() == 5 &&
		  bd2.getMinute() == 30 && bd2.getSecond() == 0);
	_test(bd2 == bd);

	bd2.set("1999-07-19 16:18:22");
	_test(bd2.getYear() == 1999 && bd2.getMonth() == 7 &&
		  bd2.getDay() == 19 && bd2.getHour() == 16 &&
		  bd2.getMinute() == 18 && bd2.getSecond() == 22);

	bd2.set(L"1951-10-1 5:30");
	_test(bd2.getYear() == 1951 && bd2.getMonth() == 10 &&
	 	  bd2.getDay() == 1 && bd2.getHour() == 5 &&
		  bd2.getMinute() == 30 && bd2.getSecond() == 0);

	// Catch invalid sets:
	try
	{
		bd2.set(1582,1,1,12);
		_fail("set(1582,1,1,12)");
	}
	catch (DateError&)
	{
		_succeed();
	}
	try
	{
		bd2.set(0,0,0);
		_fail("set(0,0,0)");
	}
	catch (DateError&)
	{
		_succeed();
	}
	try
	{
		bd2.set(1464999L,2,12);
		_fail("set(1464999L,2,12)");
	}
	catch (DateError&)
	{
		_succeed();
	}
}
