#include "MyObject2.h"
#include <iostream>
using namespace std;

Pool MyObject::pool(sizeof (MyObject), 5, true);

ostream& operator<<(ostream& os, const MyObject& o)
{
   return os << '{' << o.id << ',' << o.name << '}';
}

