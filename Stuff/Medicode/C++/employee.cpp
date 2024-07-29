// Employee.cpp
#include "Employee.h"
#include <cstring>  // <string.h>
using namespace std;

Employee::Employee(long number, const char* name, const char* address,
                   const char* phone, double salary)
{
    this->number = number;
    strcpy(this->name, name);
    strcpy(this->address, address);
    strcpy(this->phone, phone);
    this->salary = salary;
}

void Employee::setName(const char* name)
{
    strcpy(this->name, name);
}

void Employee::setAddress(const char* address)
{
    strcpy(this->address, address);
}

void Employee::setPhone(const char* phone)
{
    strcpy(this->phone, phone);
}

