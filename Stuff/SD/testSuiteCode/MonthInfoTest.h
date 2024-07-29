#ifndef MONTHINFOTEST_H
#define MONTHINFOTEST_H

#include "test.h"
#include "monthInfo.h"

class MonthInfoTest : public Test
{
public:
	MonthInfoTest()
	{}

	void run()
	{
		testValidDate();
		testEndOfMonth();
		testPreviousMonth();
		testDayOfYear();
	}
	void testValidDate()
	{
		_test(isValidDate(1582,10,15));
		_test(!isValidDate(1582,10,14));
		_test(isValidDate(1999,8,20));
		_test(isValidDate(1464999,2,11));
		_test(!isValidDate(1464999,2,12));
	}
	void testEndOfMonth()
	{
		_test(endOfMonth(1999, 1) == 31);
		_test(endOfMonth(1999, 2) == 28);
		_test(endOfMonth(1996, 2) == 29);
		_test(endOfMonth(2000, 2) == 29);
	}
	void testPreviousMonth()
	{
		_test(daysInPrevMonth(1999,3) == 28);
		_test(daysInPrevMonth(2000,3) == 29);
		_test(daysInPrevMonth(1999,1) == 31);
		_test(daysInPrevMonth(1999,12) == 30);
	}
	void testDayOfYear()
	{
		_test(dayOfYear(1999,1,1) == 1);
		_test(dayOfYear(1999,3,1) == 60);
		_test(dayOfYear(2000,3,1) == 61);
		_test(dayOfYear(1999,12,31) == 365);
		_test(dayOfYear(2000,12,31) == 366);
	}
};

#endif
