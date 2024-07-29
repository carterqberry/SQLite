#include <iostream>
#include <sstream>
#include <complex>
#include "test.h"
using namespace std;

class ComplexTest : public Test
{
    complex<double> c1;
    complex<double> c2;
    complex<double> c3;

public:
    ComplexTest()
        : c1(complex<double>(1,1)),
          c2(complex<double>(2,2)),
          c3(complex<double>(3,3))
    {}
    void run()
    {
        testEqual();
        testAdd();
    }
    void testEqual()
    {
        complex<double> c(1,1);
        _test(c == c1);
        _test(!(c == c2));
    }
    void testAdd()
    {
        _test(c1 + c2 != c3);   // failure
    }
};

int main()
{
	ComplexTest c;
	c.setStream(&cout);
	c.run();
	c.report();
}

