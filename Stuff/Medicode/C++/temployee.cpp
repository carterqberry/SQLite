// temployee.cpp
#include <iostream>
#include "employee.h"
using namespace std;

int main()
{
    Employee e(101, "albert einstein", "Princeton, NJ",
               "123-4567", 100000L);
    e.giveRaise(-10);
    cout << '{' << e.getNumber() << ',' << e.getName()
         << ',' << e.getAddress() << ',' << e.getPhone()
         << ',' << e.getSalary() << endl;
}
