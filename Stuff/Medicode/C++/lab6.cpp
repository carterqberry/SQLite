// lab6.cpp

#include <iostream>
using namespace std;

class Vehicle
{
public:
    virtual void stop() = 0;
    virtual void go() = 0;
    virtual ~Vehicle()
    {
        cout << "~Vehicle\n";
    }
};

class Car : public Vehicle
{
public:
    void stop()
    {
        cout << "Car::stop\n";
    }
    void go()
    {
        cout << "Car::go\n";
    }
    ~Car()
    {
        cout << "~Car\n";
    }
};

class Truck : public Vehicle
{
public:
    void stop()
    {
        cout << "Truck::stop\n";
    }
    void go()
    {
        cout << "Truck::go\n";
    }
    ~Truck()
    {
        cout << "~Truck\n";
    }
};

int main()
{
    Vehicle* v[] = {new Car, new Truck};
    int nv = sizeof v / sizeof v[0];
    for (int i = 0; i < nv; ++i)
    {
        v[i]->stop();
        v[i]->go();
        delete v[i];
    }
}

