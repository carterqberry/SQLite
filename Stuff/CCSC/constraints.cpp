// Work-around for template constraints
// Based on an example of Bjarne Stroustrup
// delivered at Software Development Conference, 2004.
#include <string>
using namespace std;

// A constraint class (inspects T for operations)
template<typename T>
struct Comparable {
   static void constraint(T a, T b) {
      // Exercise required operations (errors will point here)
      (void)(a < b);
      (void)(a <= b);
   }
   Comparable() {
      // Force instantiation of static function above
      void (*p)(T,T) = constraint;
   }
};

template<typename T>
class Subject : private Comparable<T>
{};

// A class that is not comparable
struct Foo{};

int main() {
   Subject<int> s1;
   Subject<string> s2;
   Subject<Foo> s3;
}

/* Output:
C:\constraints.cpp(12) : Error: illegal operand types
Had: Foo
and: Foo
C:\constraints.cpp(13) : Error: illegal operand types
Had: Foo
and: Foo
--- errorlevel 1
*/
