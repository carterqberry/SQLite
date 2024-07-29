#include <iostream>
using namespace std;

class C
{
public:
    C() {x = 0;}
    C(int i) {x = i;}
    int x;
};

int main()
{
    C c1(1);
    C c2(c1);
    cout << c2.x << endl;
}
