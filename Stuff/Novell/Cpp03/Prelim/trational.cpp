// trational.cpp: Tests the Rational class
// Author: Chuck Allison
#include <cassert>
#include <iostream>
#include <limits>
#include "Rational.h"
using namespace std;

int main()
{
   // Test constructor and operator <<:
   Rational r1, r2(1), r3(2,3);
   cout << "r1 == " << r1 << endl;
   cout << "r2 == " << r2 << endl;
   cout << "r3 == " << r3 << endl;

   // Test operator>> in a loop
   bool done = false;
   while (!done)
   {
      cout << "Enter a rational number: ";
      cin >> r1;
      if (!cin)
      {
         cout << "Invalid input\n";
         cin.clear();
      }
      else
      {
         cout << "You entered: " << r1 << endl;
         if (r1 == 0) // Uses == (could use getNumerator(), if provided)
            done = true;
      }
   }

   // The following call to istream::ignore() clears
   // the input buffer up to the next newline.
   // This handles both cases of input. If there was
   // an error, it consumes the rest of the line that
   // wasn't read by operator<< (including the newline).
   // Otherwise, it just consumes the newline after the
   // valid console input.
   cin.ignore(numeric_limits<streamsize>::max(), '\n');

   // Do some arithmetic:
   cout << "Enter the Rational 1/2: ";
   cin >> r1;
   cout << "You entered " << r1 << endl;
   cout << "Enter the Rational 3/4: ";
   cin >> r2;
   cout << "You entered " << r2 << endl;

   // Test Addition (should be 5/4 or 1.25):
   Rational result = r1 + r2;
   assert(result == Rational(5,4));
   cout << "r1 + r2 == " << result << endl;

   // Test Subtraction (should be -1/4 or -.25):
   result = r1 - r2;
   assert(result == Rational(-1,4));
   cout << "r1 - r2 == " << result << endl;

   // Test Multiplication (should be 3/8 or .375):
   result = r1 * r2;
   assert(result == Rational(3,8));
   cout << "r1 * r2 == " << result << endl;

   // Test Division (should be 2/3 or .666667):
   result = r1 / r2;
   assert(result == Rational(2,3));
   cout << "r1 / r2 == " << result << endl;

   // Test Assignments
   result = r1;
   result += r2;
   assert(result == Rational(5,4));
   cout << "r1 += r2 == " << result << endl;

   result = r1;
   result -= r2;
   assert(result == Rational(-1,4));
   cout << "r1 -= r2 == " << result << endl;

   result = r1;
   result *= r2;
   assert(result == Rational(3,8));
   cout << "r1 *= r2 == " << result << endl;

   result = r1;
   result /= r2;
   assert(result == Rational(2,3));
   cout << "r1 /= r2 == " << result << endl;

   // *** EXTRA CREDIT ***
   // Test Relationals
   assert(r1 == r1);
   assert(r2 == r2);
   assert(r1 < r2);
   assert(r2 > r1);
   assert(r2 >= r1);
   assert(r1 <= r1);
   assert(r1 != r2);

   // Test Increment/decrement
   cout << "\n r1 is now " << r1 << " and r2 is " << r2 << endl;
   r2 = r1++;
   cout << "After \"r2 = r1++\", r1 == " << r1 << ", r2 == " << r2 << endl;
   r2 = ++r1;
   cout << "After \"r2 = ++r1\", r1 == " << r1 << ", r2 == " << r2 << endl;
   r2 = r1--;
   cout << "After \"r2 = r1--\", r1 == " << r1 << ", r2 == " << r2 << endl;
   r2 = --r1;
   cout << "After \"r2 = --r1\", r1 == " << r1 << ", r2 == " << r2 << endl;
}

/* Sample Output:
r1 == 0/1
r2 == 1/1
r3 == 2/3
Enter a rational number: 2/3
You entered: 2/3
Enter a rational number: 6/-2
You entered: -3/1
Enter a rational number: 0/1
You entered: 0/1
Enter the Rational 1/2: 1/2
You entered 1/2
Enter the Rational 3/4: 3/4
You entered 3/4
r1 + r2 == 5/4
r1 - r2 == -1/4
r1 * r2 == 3/8
r1 / r2 == 2/3
r1 += r2 == 5/4
r1 -= r2 == -1/4
r1 *= r2 == 3/8
r1 /= r2 == 2/3

r1 is now 1/2 and r2 is 3/4
After "r2 = r1++", r1 == 3/2, r2 == 1/2
After "r2 = ++r1", r1 == 5/2, r2 == 5/2
After "r2 = r1--", r1 == 3/2, r2 == 5/2
After "r2 = --r1", r1 == 1/2, r2 == 1/2
*/
