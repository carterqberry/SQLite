// Illustrates "operator[][]"
#include <iomanip>
#include <iostream>
#include <cstddef>
using namespace std;

class Index
{
  int *data;
  size_t size;

public:
  Index(size_t n = 5)
  {
    data = new int[n];
    for (size_t i = 0; i < n; ++i)
      data[i] = i;
    size = n;
  }
  ~Index()
  {
    delete [] data;
  }
  size_t getSize() const {return size;}
  int& operator[](size_t i)
  {
    if (i >= size)
      throw "index error";
    return data[i];
  }
  int operator[](size_t i) const
  {
    if (i >= size)
      throw "index error";
    return data[i];
  }
};

class DoubleIndex
{
  Index *data;
  size_t size;

public:
  DoubleIndex(size_t n = 10)
  {
    data = new Index[n];
    for (size_t i = 0; i < n; ++i)
      for (size_t j = 0; j < data[i].getSize(); ++j)
        data[i][j] = i+j;
    size = n;
  }
  ~DoubleIndex()
  {
    delete [] data;
  }
  size_t getSize() const {return size;}
  Index& operator[](size_t i)
  {
    if (i >= size)
      throw "index error";
    return data[i];
  }
  const Index& operator[](size_t i) const
  {
    if (i >= size)
      throw "index error";
    return data[i];
  }
};

int main()
{
    DoubleIndex a(10);
    for (size_t i = 0; i < a.getSize(); ++i)
    {
      for (size_t j = 0; j < a[i].getSize(); ++j)
        cout << setw(4) << a[i][j] << ' ';
      cout << endl;
    }
    cout << endl;

    a[2][3] = 99;
    a[3][4] = 999;
    for (size_t i = 0; i < a.getSize(); ++i)
    {
      for (size_t j = 0; j < a[i].getSize(); ++j)
        cout << setw(4) << a[i][j] << ' ';
      cout << endl;
    }
}

/* Output:
   0    1    2    3    4 
   1    2    3    4    5 
   2    3    4    5    6 
   3    4    5    6    7 
   4    5    6    7    8 
   5    6    7    8    9 
   6    7    8    9   10 
   7    8    9   10   11 
   8    9   10   11   12 
   9   10   11   12   13 

   0    1    2    3    4 
   1    2    3    4    5 
   2    3    4   99    6 
   3    4    5    6  999 
   4    5    6    7    8 
   5    6    7    8    9 
   6    7    8    9   10 
   7    8    9   10   11 
   8    9   10   11   12 
   9   10   11   12   13 
*/
