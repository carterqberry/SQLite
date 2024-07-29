#include <iostream>
#include <ctime>
using namespace std;

class Time
{
   int hours;
   int minutes;
   int seconds;
public:
   Time();
   Time(int hrs, int mins, int secs);
   void display();
};

//The Default Constructor:
Time::Time()
{
   time_t tval = time(0);
   tm* pTimeInfo = localtime(&tval);
   hours = pTimeInfo->tm_hour;
   minutes = pTimeInfo->tm_min;
   seconds = pTimeInfo->tm_sec;
}

Time::Time(int hrs, int mins, int secs)
{
   hours = hrs;
   minutes = mins;
   seconds = secs;
}

void Time::display()
{
   cout << hours << ':' << minutes << ':' << seconds << endl;
}

int main()
{
   Time now;
   now.display();
   Time then(8, 15, 10);
   then.display();
}

