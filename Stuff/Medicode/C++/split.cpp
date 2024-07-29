#include "split.h"

long split(double x, double& frac)
{
    long whole = static_cast<long>(x);
    frac = x - whole;
    return whole;
}
