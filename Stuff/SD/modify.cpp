#include <iostream>
#include <string>
using namespace std;

class MyError
{
    string msg;
public:
    MyError(const string& s = "") : msg(s) {}
    void append(const string& s)
    {
        msg += s;
    }
    string what() const
    {
        return msg;
    }
};

int main()
{
    void f();

    try
    {
        f();
    }
    catch(MyError& m)
    {
        cout << m.what() << endl;
    }
}

void f()
{
    try
    {
        throw MyError("part 1");
    }
    catch(MyError& m)
    {
        m.append("; part2");
        throw;
    }
}

/* Output:
part1; part2
*/

