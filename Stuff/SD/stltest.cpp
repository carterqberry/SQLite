#include <iostream>
#include <vector>
using namespace std;

class Foo {
public:
   ~Foo(){cout << "~Foo\n";}
};
 int main() {
    vector<Foo> v;
    v.push_back(Foo());
}

/* Output:
~Foo
~Foo
*/
