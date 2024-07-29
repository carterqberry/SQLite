// min_element.cpp: Illustrates unit test for finding the minimum of a sequence

// The code to be tested
int min_element(int a[], int n) {
    int pos = -1;
    if (n > 0) {
        ++pos;
        for (int i = 1; i < n; ++i)
            if (a[i] < a[pos])    //*
                pos = i;
    }
    return pos;
}

// The unit test
#include "test.h"

int main() {
    int a[] = {7,2,8,1,4};
    int b[] = {2,2,2};
    int c[] = {1,2,8,7,4};
    int d[] = {7,2,8,4,1};
    test_(min_element(0,0) == -1);
    test_(min_element(a,3) == 1);
    test_(min_element(a,5) == 3);
    test_(min_element(b,3) == 0);
    test_(min_element(c,5) == 0);
    test_(min_element(d,5) == 4);
    report_();
}
