// sort.cpp: Tests a Simple sorting algorithm
void sort(int a[], int n) {
    for (int i = 0; i < n-1; ++i)
        for (int j = i+1; j < n; ++j) {
            if (a[i] > a[j]) {  // Forgot this
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;   // Was a[j] = a[i]
            }
        }
}

#include "test.h"
void test_sort(int a[], int n) {
    sort(a, n);
    bool pass = true;
    for (int i = 0; i < n-1; ++i)
        if (a[i] > a[i+1]) {
            pass = false;
            break;
        }
    test(pass);
}

int main() {
    int a[] = {7,2,8,1,4};
    test_sort(a, 5);
    test_sort(a, 0);
    report();
}
