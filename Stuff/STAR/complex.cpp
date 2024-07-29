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
      : c1(1,1), c2(2,2), c3(3,3)
    {}
    void run()
    {
        testEqual();
        testAdd();
    }
    void testEqual()
    {
        complex<double> c1(1,1);
        test_(c1 == c1);
        test_(!(c1 == c2));
    }
    void testAdd()
    {
        test_(c1 + c2 != c3);   // failure
    }
};

int main()
{
	ComplexTest c;
	c.run();
	c.report();
}

/* Output:
ComplexTestfailure: (c1 + c2 != c3) , complex.cpp (line 30)
Test "ComplexTest":
	Passed: 2	Failed: 1
*/

