#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
   vector<bool> vb;
   vb.push_back(1);
   vb.push_back(0);
   vb.push_back(1);
   vb.push_back(1);
   vb.push_back(0);
   vector<bool>::iterator p = vb.begin();
   while (p != vb.end())
      cout << *p++;
   cout << endl;
   p = find(vb.begin(), vb.end(), 0);
   if (p != vb.end())
       cout << "Found in position " << p - vb.begin() << endl;
}

/* Output:
10110
Found in position 1
*/

