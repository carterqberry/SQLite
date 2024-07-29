#ifndef MATHSTUFF_H
#define MATHSTUFF_H

// mathstuff.h
inline int signum(double x)
{
    return x < 0.0 ? -1 : (x > 0.0 ? 1 : 0);
}

double round(double x, int places = 0);

#endif
