// employee.cpp: Using structs for data only
#include <iostream>
#include <string>
using namespace std;

struct Employee {
   string name;
   int birthMonth;
   int birthDay;
   int birthYear;
   double salary;
};


int main() {
   Employee e;
   e.name = "John Doe";
   e.birthMonth = 10;
   e.birthDay = 1;
   e.birthYear = 1971;
   cout << e.name << "'s birthday: " << e.birthMonth << '/' << e.birthDay << '/'
        << e.birthYear << endl;
   Employee* p = &e;
   cout << p->name << "'s birthday: " << p->birthMonth << '/' << p->birthDay << '/'
        << p->birthYear << endl;
}

/* Output:
John Doe's birthday: 10/1/1971
John Doe's birthday: 10/1/1971
*/
