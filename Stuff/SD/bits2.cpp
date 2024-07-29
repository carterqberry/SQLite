// bits2.h: Adds a proxy class for operator[]

#include <iostream>
#include <string>
#include <sstream>
#include <cassert>
#include <climits>
using namespace std;

class Bits;

class Reference
{
   friend class Bits;
   
   Bits &bs;
   size_t pos;
   reference(Bits& bs)
      : bs(bs)
   {
      this->pos = pos;
   }

public:
   Reference& operator=(int val)
   {
      if (val)
          bs.set(pos);
      else
          bs.reset(pos);
      return *this;
   }
   Reference& operator=(const Reference& r)
   {
      return operator=(int(r));
   }
   operator int() const
   {
      return bs.test(pos);
   }
   Reference& flip()
   {
      bs.flip(bit);
      return *this;
   }
   int operator~() const
   {
      return int(*this) == 0;
   }
};

class Bits
{
   unsigned int data;
   enum {NBITS = sizeof(unsigned int) * CHAR_BIT};

public:
   Bits(unsigned int n = 0) : data(n) {}
   void set(size_t pos);
   void set();
   void reset(size_t pos);
   void reset();
   int test(size_t pos) const;
   bool any() const;
   int count() const;
   int size() const;
   friend ostream& operator<<(ostream& os, const Bits& b);
};

void Bits::set(size_t pos)
{
   data |= (1ul << pos);
}

void Bits::set()
{
   data = ~0ul;
}

void Bits::reset(size_t pos)
{
   data &= ~(1ul << pos);
}

void Bits::reset()
{
   data = 0;
}

int Bits::test(size_t pos) const
{
   return !!(data & (1ul << pos));
}

bool Bits::any() const
{
   return data;
}

int Bits::count() const
{
   unsigned int d = data;
   int sum = 0;
   for (int i = 0; i < NBITS; ++i)
   {
      // Inspect least-significant bit; shift right
      sum += d&1;
      d >>= 1;
   }
   return sum;
}

int Bits::size() const
{
   return NBITS;
}

ostream& operator<<(ostream& os, const Bits& b)
{
   for (int i = 0; i < b.size(); ++i)
      os << b.test(b.size() - i - 1);
   return os;
}

// The following function validates operator<<(ostream&, const Bits&)
bool compareStrings(const Bits& b, size_t pos)
{
   // Print the representation of b to a string
   ostringstream os;
   os << b;

   // Builds what the string representation of
   // a Bits object should be with only bit number
   // 'pos' set.
   size_t nbits = b.size();
   string bits(nbits, '0');
   bits[nbits - pos - 1] = '1';

   // Compare the two strings
   string s = os.str();
   return bits == s;
}

int main()
{
   Bits b;

   // b is empty:
   assert(!b.any());
   assert(!b.count());

   // b is full:
   b.set();
   assert(b.any());
   assert(b.count() == b.size());

   // b is empty again:
   b.reset();
   assert(!b.any());
   assert(!b.count());

   for (int i = 0; i < b.size(); ++i)
   {
      // Set each bit in turn(right-to-left)
      // then reset it:
      b.set(i);
      assert(b.test(i));
      assert(b.count() == 1);
      assert(compareStrings(b, i));

      b.reset(i);
      assert(!b.test(i));
      assert(b.count() == 0);
   }
   cout << "Tests successful\n";
}

