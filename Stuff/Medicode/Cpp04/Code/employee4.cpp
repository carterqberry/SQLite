// employee4.cpp: Declares functions const (and adds a non-const function)

#include <iostream>
#include <ctime>
#include <sstream>
#include <string>
using namespace std;

class Employee {
   string name;
   int birthMonth;
   int birthDay;
   int birthYear;
   double salary;

public:
   // A constructor
   Employee(const string& name, int month, int day, int year, double salary)
   : name(name)  // Initializer list
   {
      // These could also appear in the initializer list
      birthMonth = month;
      birthDay = day;
      birthYear = year;
      this->salary = salary;   // "this" points to the object in use
   }

   // Other member functions
   double computePay(double periods) const {
      return periods * salary;
   }
   double ageInDays() const {
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
   string toString() const {
      ostringstream os;
      os << '{' << name << ',' << birthMonth << '/' << birthDay
         << '/' << birthYear << ",$" << salary << '}';
      return os.str();
   }
   // A new, non-const function
   void changeSalary(double newSalary) {
      salary = newSalary;
   }
};

int main() {
   Employee e("John Doe", 10, 1, 1971, 30000.00);
   cout << "Employee: " << e.toString() << " is " << e.ageInDays() << " days old\n";
   e.changeSalary(40000.00);
   cout << "Employee: " << e.toString() << " is " << e.ageInDays() << " days old\n";

   // A const Employee:
   const Employee e2("Jane Dough", 5, 1, 1974, 50000.00);
   cout << "Employee: " << e2.toString() << " is " << e2.ageInDays() << " days old\n";
   // e2.changeSalary(60000.00); // COMPILE ERROR!
}

/* Output:
Employee: {John Doe,10/1/1971,$30000} is 11971.8 days old
Employee: {John Doe,10/1/1971,$40000} is 11971.8 days old
Employee: {Jane Dough,5/1/1974,$50000} is 11028.8 days old
*/
