#include <exception>
#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

int main()
{
    try
    {
        string s;
        cout << s.at(100);     // error
    }
    catch (exception& x)
    {
        cout << typeid(x).name()
             << ": " << x.what()
             << endl;
    }
}

