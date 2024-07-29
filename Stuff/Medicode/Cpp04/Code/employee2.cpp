// employee2.cpp: A first look at classes (adding member functions)
#include <iostream>
#include <ctime>
#include <sstream>
#include <string>
using namespace std;

struct Employee {
   // Member data
   string name;
   int birthMonth;
   int birthDay;
   int birthYear;
   double salary;

   // A constructor
   Employee(const string& name, int month, int day, int year,
            double salary)
   : name(name)  // Initializer list
   {
      // These could also appear in the initializer list
      birthMonth = month;
      birthDay = day;
      birthYear = year;
      this->salary = salary;   // "this" points to the object in use
   }

   // Other member functions
   double computePay(double periods) {
      return periods * salary;
   }
   double ageInDays() {
      enum {SECS_PER_DAY = 24*60*60};

      // Get today's date (encoded value)
      time_t tval = time(0);

      // Encode birth date
      tm bdate;
      bdate.tm_hour = 0;
      bdate.tm_min = 0;
      bdate.tm_sec = 0;
      bdate.tm_mon = birthMonth - 1;   // tm_mon is in [0-11]!
      bdate.tm_mday = birthDay;
      bdate.tm_year = birthYear;
      time_t bval = mktime(&bdate);
      double diff = difftime(tval, bval);
      return diff / SECS_PER_DAY;
   }
   string toString() {
      ostringstream os;
      os << '{' << name << ',' << birthMonth << '/' << birthDay
         << '/' << birthYear << ",$" << salary << '}';
      return os.str();
   }
};

int main() {
   Employee e("John Doe", 10, 1, 1971, 30000.00);
   cout << "Employee: " << e.toString() << " is " << e.ageInDays() << " days old\n";
   Employee* p = &e;
   cout << "Employee: " << p->toString() << " is " << p->ageInDays() << " days old\n";
}

/* Output:
Employee: {John Doe,10/1/1971,$30000} is 11971.8 days old
Employee: {John Doe,10/1/1971,$30000} is 11971.8 days old
*/
