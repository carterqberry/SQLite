// mathstuff.cpp
#include "mathstuff.h"
#include <math.h>
#include <assert.h>

double round(double x, int places)
{
    // rounds to the nearest decimal place
    assert(places >= 0);

    double temp = x;
    if (places > 0)
        temp *= pow(10, places);
    temp += signum(x)*0.5;

    double whole;
    (void) modf(temp, &whole);
    if (places > 0)
        whole /= pow(10, places);
    return whole;
}

