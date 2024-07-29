// employee.cpp: A first look at classes
#include <iostream>
#include <string>
using namespace std;

class Employee {
   string lastName;
   string firstName;
   int birthMonth;
   int birthDay;
   int birthYear;
public:
   // A constructor
   Employee(const string& last, const string& first,
            int month, int day, int year)
   : lastName(last), firstName(first)  // Initializer list
   {
      // These could also appear in the initializer list
      birthMonth = month;
      birthDay = day;
      birthYear = year;
   }

