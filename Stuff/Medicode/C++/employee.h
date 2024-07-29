#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee
{
public:
    Employee(long, const char*, const char*, const char*, double);
    long getNumber();
    const char* getName();
    const char* getAddress();
    const char* getPhone();
    double getSalary();
    void setName(const char*);
    void setAddress(const char*);
    void setPhone(const char*);
    void setSalary(double);
    void giveRaise(double);

private:
    long number;
    char name[31];
    char address[31];
    char phone[11];
    double salary;
};

inline long Employee::getNumber()
{
    return number;
}

inline const char* Employee::getName()
{
    return name;
}

inline const char* Employee::getAddress()
{
    return address;
}

inline const char* Employee::getPhone()
{
    return phone;
}

inline double Employee::getSalary()
{
    return salary;
}

inline void Employee::giveRaise(double percent)
{
    salary *= 1 + percent/100.0;
}

inline void Employee::setSalary(double salary)
{
    this->salary = salary;
}

#endif

