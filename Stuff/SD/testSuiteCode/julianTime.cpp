// Handles dates from Oct. 15, 1582 (2299161)
// to Feb. 11, 1,464,999 (536800999)

#include "julianTime.h"
#include <cmath>
#include <ctime>
#include <cassert>

using namespace std;
using namespace DateStuff;

double DateStuff::gregToJul()
{
    // Get today as a Julian
    time_t now = time(0);
    struct tm* fields = localtime(&now);
    long yr;
    int mon, day, hr, min, sec;
    
    yr = fields->tm_year+1900;
    mon = fields->tm_mon + 1;
    day = fields->tm_mday;
    hr = fields->tm_hour;
    min = fields->tm_min;
    sec = fields->tm_sec;
    return gregToJul(yr, mon, day, hr, min, sec);
}

void DateStuff::julToGreg(double jday, long& year, int& month,
                       int& day, int& hour, int& minute,
                       int& second)
{
    // Converts Julian day number to Gregorian date and time
    assert(jday >= DateStuff::min);	// MS requires DateStuff::
    double norm = jday + 0.5;       // Add 12 hours
    double whole;
    double frac = modf(norm, &whole);

    j2g(static_cast<long>(whole), year, month, day);

    long secs = static_cast<long>(frac*86400.0 + 0.5);
    hour = secs/3600;
    secs -= hour*3600;
    minute = secs/60;
    second = secs - minute*60;
}

double DateStuff::gregToJul(long year, int month, int day,
                            int hrs, int min, int sec)
{
	bool goodMonth = (1 <= month && month <= 12);
	bool goodDay = (1 <= day && day <= 31);		// not rigorous
	bool goodHour = (0 <= hrs && hrs <= 24);	// not 23
	bool goodMin = (0 <= min && min <= 60);		// not 59
	bool goodSec = (0 <= sec && sec <= 60);		// not 59
    bool bigEnough =
		(year > 1582 ||
         year == 1582 && (month > 10 ||
                          month == 10 && day >= 15));
    bool smallEnough =
		(year < 1464999 ||
         year == 1464999 && (month < 2 ||
                             month == 2 && day <= 11));
	if (!goodMonth || !goodDay || !goodHour || !goodMin ||
		!goodSec || !bigEnough || !smallEnough)
		return 0.0;

    // converts Gregorian date/time to real Julian day number
    long jd = g2j(year, month, day);
    return double(jd) + ((hrs - 12.0)
                      + (min + sec/60.0) / 60.0 ) / 24.0;
}

std::string DateStuff::julToStr(double jd)
{
	using namespace std;
    long y;
    int mo, d, h, mi, s;
    julToGreg(jd, y, mo, d, h, mi, s);
    char buf[23];   // YYYYYYY-MM-DD HH:MM:SS
    sprintf(buf, "%ld-%02d-%02d %02d:%02d:%02d", y, mo, d, h, mi, s);
    return string(buf);
}

std::wstring DateStuff::julToWStr(double jd)
{
	using namespace std;
    long y;
    int mo, d, h, mi, s;
    julToGreg(jd, y, mo, d, h, mi, s);
    wchar_t buf[23];   // YYYYYYY-MM-DD HH:MM:SS
    swprintf(buf, L"%ld-%02d-%02d %02d:%02d:%02d", y, mo, d, h, mi, s);
    return wstring(buf);
}

double DateStuff::strToJul(const std::string& str)
{
	using namespace std;
    // Assumes Y..Y-MM-DD[ HH:MM:SS]
    long y;
    int mo, d, h = 12, mi = 0, s = 0;
    const char* ptr = str.c_str();
    char* end = 0;
    
    // Extract year:
    y = strtol(ptr, &end, 10);
    if (y < 1582 || y > 1464999 || *end != '-')
        return 0.0;
    
    // Extract month:
    mo = strtol(++end, &end, 10);    // ++ => skip '-'
    if (mo < 0 || mo > 12 || *end != '-')
        return 0.0;
    
    // Extract day:
    d = strtol(++end, &end, 10);
    if (d < 0 || d > 31)
        return 0.0;

    if (*end)
    {
        if (*end != ' ')
            return 0.0;

        // Extract hour:
        h = strtol(++end, &end, 10);
        if (h < 0 || h > 24)
            return 0.0;

        if (*end)
        {
            if (*end != ':')
                return 0.0;

            // Extract minute:
            mi = strtol(++end, &end, 10);
            if (mi < 0 || mi > 60)
                return 0.0;

            if (*end)
            {
                if (*end != ':')
                    return 0.0;

                // Extract second:
                s = strtol(++end, 0, 10);
                if (s < 0 || s > 60)
                    return 0.0;
            }
        }
    }
    return gregToJul(y,mo,d,h,mi,s);
}

double DateStuff::wstrToJul(const std::wstring& str)
{
	using namespace std;
    // Assumes Y..Y-MM-DD[ HH:MM:SS]
    long y;
    int mo, d, h = 12, mi = 0, s = 0;
    const wchar_t* ptr = str.c_str();
    wchar_t* end = 0;
    
    // Extract year:
    y = wcstol(ptr, &end, 10);
    if (y < 1582 || y > 1464999 || *end != wchar_t('-'))
        return 0.0;
    
    // Extract month:
    mo = wcstol(++end, &end, 10);    // ++ => skip '-'
    if (mo < 0 || mo > 12 || *end != wchar_t('-'))
        return 0.0;
    
    // Extract day:
    d = wcstol(++end, &end, 10);
    if (d < 0 || d > 31)
        return 0.0;

    if (*end)
    {
        if (*end != wchar_t(' '))
            return 0.0;

        // Extract hour:
        h = wcstol(++end, &end, 10);
        if (h < 0 || h > 24)
            return 0.0;

        if (*end)
        {
            if (*end != wchar_t(':'))
                return 0.0;

            // Extract minute:
            mi = wcstol(++end, &end, 10);
            if (mi < 0 || mi > 60)
                return 0.0;

            if (*end)
            {
                if (*end != wchar_t(':'))
                    return 0.0;

                // Extract second:
                s = wcstol(++end, 0, 10);
                if (s < 0 || s > 60)
                    return 0.0;
            }
        }
    }
    return gregToJul(y,mo,d,h,mi,s);
}

