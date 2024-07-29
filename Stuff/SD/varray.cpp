#include <valarray>
#include <iostream>
using namespace std;

#define trace1(x) cout << #x ": " << x << endl
#define trace(expr) print(#expr, expr)

template<class T>
void print(const char* lbl, const valarray<T>& a)
{
    cout << lbl << ": ";
    for (size_t i = 0; i < a.size(); ++i)
        cout << a[i] << ' ';
    cout << endl;
}

double f(double x)
{
    return 2.0*x - 1.0;
}

int main()
{
    double a = 2.0, b = 3.0, c = 4.0;
    double data1[] = {10.0, 20.0, 30.0, 40.0};
    double data2[] = {40.0, 30.0, 20.0, 10.0};
    valarray<double> v1(data1, 4);
    valarray<double> v2(data2, 4);
    trace(v1);
    trace(v2);
    trace(v1 == v2);
    trace(v1 != v2);

/* Output:
v1: 10 20 30 40 
v2: 40 30 20 10 
v1 == v2: 0 0 0 0
v1 != v2: 1 1 1 1
*/

    // Do some math
    trace(v1 + v2);
    trace(v1 - v2);
    trace(v1 * v2);
    trace(v1 / v2);

/* Output:
v1 + v2: 50 50 50 50 
v1 - v2: -30 -10 10 30 
v1 * v2: 400 600 600 400 
v1 / v2: 0.25 0.666667 1.5 4 
*/

    // Do some more
    trace(b*v1);
    trace(b*v1 + c);
    trace(v1*v1);
    trace(a*v1*v1);
    trace(a*v1*v1 + b*v1 + c);

/* Output:
b*v1: 30 60 90 120 
b*v1 + c: 34 64 94 124 
v1*v1: 100 400 900 1600 
a*v1*v1: 200 800 1800 3200 
a*v1*v1 + b*v1 + c: 234 864 1894 3324 
*/

    trace(v1.shift(2));
    trace(v1.cshift(2));
    trace1(v1.min());
    trace1(v1.max());
    trace1(v1.sum());
    trace(pow(v1, 3.0));
    trace(sin(v1) + cos(v2));
    trace(v1.apply(f));

/* Output:
v1.shift(2): 30 40 0 0 
v1.cshift(2): 30 40 10 20 
v1.min(): 10
v1.max(): 40
v1.sum(): 100
pow(v1, 3.0): 1000 8000 27000 64000 
sin(v1) + cos(v2): -1.21096 1.0672 -0.57995 -0.0939584 
v1.apply(f): 19 39 59 79 
*/

    // Extract a slice
    int data3[] = {1,2,3,4,5,6,7,8,9,10,11,12};
    valarray<int> v3(data3, 12);
    trace(valarray<int>(v3[slice(0, 4, 3)]));
    
/* Output:
valarray<int>(v3[slice(0, 4, 3)]): 1 4 7 10 
*/

    // Extract conditionally
    trace(v3 > 6);
    trace(valarray<int>(v3[v3 > 6]));

/* Output:
v3 > 6: 0 0 0 0 0 0 1 1 1 1 1 1
valarray<int>(v3[v3 > 6]): 7 8 9 10 11 12 
*/

    // Square first column
    v3[slice(0, 4, 3)] *= valarray<int>(v3[slice(0, 4, 3)]);
    trace(v3);
    trace(valarray<int>(v3[slice(0, 4, 3)]));

/* Output:
v3: 1 2 3 16 5 6 49 8 9 100 11 12 
valarray<int>(v3[slice(0, 4, 3)]): 1 16 49 100 
*/

    // Restore it
    valarray<int> save(4);
    save[0] = 1;
    save[1] = 4;
    save[2] = 7;
    save[3] = 10;
    v3[slice(0, 4, 3)] = save;
    trace(v3);

/* Output:
v3: 1 2 3 4 5 6 7 8 9 10 11 12 
*/
    
    // Extract a 2-d subset: {{1,3,5}, {7, 9, 11}}
    valarray<size_t> siz(2);
    siz[0] = 2;
    siz[1] = 3;
    valarray<size_t> gap(2);
    gap[0] = 6;
    gap[1] = 2;
    trace(valarray<int>(v3[gslice(0, siz, gap)]));

/* Output:
valarray<int>(v3[gslice(0, siz, gap)]): 1 3 5 7 9 11 
*/

    // Extract a subset via a boolean mask (bool elements)
    valarray<bool> mask(5);
    mask[1] = mask[2] = mask[4] = true;
    trace(/*valarray<int>(*/v3[mask]/*)*/);

/* Output:
valarray<int>(v3[mask]): 2 3 5 
*/

    // Extract a subset via an index mask (size_t elements)
    valarray<size_t> idx(4);
    idx[0] = 2;
    idx[1] = 2;
    idx[2] = 3;
    idx[3] = 6;
    trace(valarray<int>(v3[idx]));

/* Output:
valarray<int>(v3[idx]): 3 3 4 7 
*/

    // Use an index mask in assignment
    valarray<char> text("each peach pear plum", 20);
    valarray<char> caps("EPPP", 4);
    idx[0] = 0;
    idx[1] = 5;
    idx[2] = 11;
    idx[3] = 16;
    text[idx] = caps;
    trace(text);

/* Output:
text: E a c h   P e a c h   P e a r   P l u m 
*/
}

/* Output:
v1: 10 20 30 40 
v2: 40 30 20 10 
v1 == v2: 0 0 0 0 
v1 != v2: 1 1 1 1 
v1 + v2: 50 50 50 50 
v1 - v2: -30 -10 10 30 
v1 * v2: 400 600 600 400 
v1 / v2: 0.25 0.666667 1.5 4 
b*v1: 30 60 90 120 
b*v1 + c: 34 64 94 124 
v1*v1: 100 400 900 1600 
a*v1*v1: 200 800 1800 3200 
a*v1*v1 + b*v1 + c: 234 864 1894 3324 
v1.shift(2): 30 40 0 0 
v1.cshift(2): 30 40 10 20 
v1.min(): 10
v1.max(): 40
v1.sum(): 100
pow(v1, 3.0): 1000 8000 27000 64000 
sin(v1) + cos(v2): -1.21096 1.0672 -0.57995 -0.0939584 
v1.apply(f): 19 39 59 79 
valarray<int>(v3[slice(0, 4, 3)]): 1 4 7 10 
v3 > 6: 0 0 0 0 0 0 1 1 1 1 1 1 
valarray<int>(v3[v3 > 6]): 7 8 9 10 11 12 
v3: 1 2 3 16 5 6 49 8 9 100 11 12 
valarray<int>(v3[slice(0, 4, 3)]): 1 16 49 100 
v3: 1 2 3 4 5 6 7 8 9 10 11 12 
valarray<int>(v3[gslice(0, siz, gap)]): 1 3 5 7 9 11 
valarray<int>(v3[mask]): 2 3 5 
valarray<int>(v3[idx]): 3 3 4 7 
text: E a c h   P e a c h   P e a r   P l u m 
*/

