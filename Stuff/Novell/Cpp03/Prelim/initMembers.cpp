#include <iostream>
using namespace std;

class Member1
{
public:
   Member1()
   {
      cout << "Constructing a Member1 object\n";
   }
};


class Member2
{
public:
   Member2()
   {
      cout << "Constructing a Member2 object\n";
   }
};

class Wrapper
{
   Member2 mem2;
   Member1 mem1;
public:
   Wrapper()
   {
      cout << "Constructing a Wrapper\n";
   }
};

int main()
{
   Wrapper w;
}

