// Handles dates from Oct. 15, 1582 (2299161)
// to Feb. 11, 1,464,999 (536800999)

#include "julianDate.h"
#include <ctime>
#include <cassert>

using namespace std;
using namespace DateStuff;

long DateStuff::g2j(long year, int month, int day)
{
	// Validate date:
	bool goodMonth = (1 <= month && month <= 12);
	bool goodDay = (1 <= day && day <= 31);	// not rigorous
    bool bigEnough =
		(year > 1582 ||
         year == 1582 && (month > 10 ||
                          month == 10 && day >= 15));
    bool smallEnough =
		(year < 1464999 ||
         year == 1464999 && (month < 2 ||
                             month == 2 && day <= 11));
	if (!goodMonth || !goodDay || !bigEnough || !smallEnough)
		return 0;

    long m = month;
    long d = day;
    long y = year;

    // Convert Gregorian date to integral Julian day number.
	// From CACM, Vol. 11, no. 10, October 1968, p. 657)
    return d - 32075L
             + 1461L * (y + 4800 + (m - 14L)/12L) / 4L
             +  367L * (m - 2L - (m - 14L)/12L * 12L) / 12L
             -    3L * ((y + 4900L + (m - 14L)/12L)/100L) / 4L;
}

long DateStuff::g2j()
{
    // Get today as an integer Julian
    time_t now = time(0);
    struct tm* fields = localtime(&now);
    long yr;
    int mon, day;
    
    yr = fields->tm_year+1900;
    mon = fields->tm_mon + 1;
    day = fields->tm_mday;
    return g2j(yr, mon, day);
}

void DateStuff::j2g(long jday, long& year, int& month, int& day)
{
    // Converts integral Julian day number to Gregorian date
	// From CACM, Vol. 11, no. 10, October 1968, p. 657)
    assert(jday >= DateStuff::min);   // 1582-10-15
    assert(jday <= DateStuff::max);   // 1464999-2-11
    long t1 = jday + 68569L;
    long t2 = 4L*t1 / 146097L;
    t1 -= (146097L*t2 + 3L) / 4L;

    long y = 4000L*(t1 + 1)/1461001L;
    t1 = t1 - 1461L*y/4L + 31;

    long m = 80L *t1/2447L;
    day = static_cast<int>(t1 - 2447L*m/80L);

    t1 = m / 11L;
    month = static_cast<int>(m + 2L - 12L*t1);
    year = static_cast<int>(100L * (t2 - 49L) + y + t1);
}

std::string DateStuff::j2s(double jd)
{
	using namespace std;
    long y;
    int m, d;
    j2g(static_cast<long>(jd), y, m, d);
    char buf[14];   // YYYYYYY-MM-DD
    sprintf(buf, "%ld-%02d-%02d", y, m, d);
    return string(buf);
}

std::wstring DateStuff::j2ws(double jd)
{
	using namespace std;
    long y;
    int m, d;
    j2g(static_cast<long>(jd), y, m, d);
    wchar_t buf[14];   // YYYYYYY-MM-DD
    swprintf(buf, L"%ld-%02d-%02d", y, m, d);
    return wstring(buf);
}

long DateStuff::s2j(const std::string& s)
{
	using namespace std;
    long y;
    int m, d;
    const char* ptr = s.c_str();
    char* end = 0;

    // Extract year:
    y = strtol(ptr, &end, 10);
    if (y < 1582 || y > 1464999 || *end != '-')
        return 0;

    // Extract month:
    m = strtol(++end, &end, 10);    // ++ => skip '-'
    if (m < 1 || m > 12 || *end != '-')
        return 0;

    // Extract day:
    d = strtol(++end, 0, 10);
    if (d < 1 || d > 31)
        return 0;
    return g2j(y,m,d);	// does validation
}

long DateStuff::ws2j(const std::wstring& s)
{
	using namespace std;
    long y;
    int m, d;
    const wchar_t* ptr = s.c_str();
    wchar_t* end = 0;

    // Extract year:
    y = wcstol(ptr, &end, 10);
    if (y < 1582 || y > 1464999 || *end != wchar_t('-'))
        return 0;

    // Extract month:
    m = wcstol(++end, &end, 10);    // ++ => skip '-'
    if (m < 1 || m > 12 || *end != wchar_t('-'))
        return 0;

    // Extract day:
    d = wcstol(++end, 0, 10);
    if (d < 1 || d > 31)
        return 0;
    return g2j(y,m,d);	// does validation
}

