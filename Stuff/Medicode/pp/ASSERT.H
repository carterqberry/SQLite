#ifndef ASSERT_H
#define ASSERT_H

extern void __assert(char *, char *, long);

#define assert(cond) \
    ((cond)          \
       ? (void) 0    \
       : __assert(#cond,__FILE__,__LINE__))

#endif
