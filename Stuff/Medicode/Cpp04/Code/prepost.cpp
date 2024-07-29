// Overloads ++ and --
#include <iostream>
using namespace std;

class Value
{
  int data;
public:
  explicit Value(int n)
  {
    data = n;
  }
  Value& operator++()
  {
    ++data;
    return *this;
  }
  const Value operator++(int)
  {
    Value temp = *this;
    ++*this;
    return temp;
  }
  Value& operator--()
  {
    --data;
    return *this;
  }
  const Value operator--(int)
  {
    Value temp = *this;
    --*this;
    return temp;
  }
  operator int() const
  {
    return data;
  }
};

int main()
{
  Value v(5);
  Value w(v++);
  cout << v << endl;
  cout << ++w << endl;
  Value z(w--);
  cout << w << endl;
  cout << --z << endl;
}

/* Output:
6
6
5
5
*/

