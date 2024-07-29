// tbitstr.cpp: A cursory test for the bitstring class
// Simply compile along with your .cpp file.
// Author: Chuck Allison
#include <iostream>
#include "bitstr.h"
#include "test.h"
using namespace std;

// Test program
int main() {
   bitstring b;

   // Test some exceptions
   try {
      b[0];
      fail_("1: indexed empty bitstring");
   }
   catch (out_of_range&) {
      succeed_();
   }
   catch (...) {
      fail_("1: wrong exception thrown");
   }
   try {
      b.set(0);
      fail_("2: set empty bitstring");
   }
   catch (out_of_range&) {
      succeed_();
   }
   catch (...) {
      fail_("2: wrong exception thrown");
   }
   try {
      b.reset(0);
      fail_("3: reset empty bitstring");
   }
   catch (out_of_range&) {
      succeed_();
   }
   catch (...) {
      fail_("3: wrong exception thrown");
   }
   try {
      b.flip(0);
      fail_("4: flip empty bitstring");
   }
   catch (out_of_range&) {
      succeed_();
   }
   catch (...) {
      fail_("4: wrong exception thrown");
   }
   try {
      b.test(0);
      fail_("5: test empty bitstring");
   }
   catch (out_of_range&) {
      succeed_();
   }
   catch (...) {
      fail_("5: wrong exception thrown");
   }
   try {
      b.from_string(" 01");
      fail_("6: bad string in from_string");
   }
   catch (invalid_argument&) {
      succeed_();
   }
   catch (...) {
      fail_("6: wrong exception thrown");
   }
   try {
      const bitstring b2(b);
      b2[0];
      fail_("7: bad index in const bitstring");
   }
   catch (out_of_range&) {
      succeed_();
   }
   catch (...) {
      fail_("7: wrong exception thrown");
   }
   try {
      bitstring b2(string::npos);
      b2.to_string();
      fail_("8: length error in to_string");
   }
   catch (length_error&) {
      succeed_();
   }
   catch (...) {
      fail_("8: wrong exception thrown");
   }
   try {
      b.pop();
      fail_("9: underflow error in pop");
   }
   catch (domain_error&) {
      succeed_();
   }
   catch (...) {
      fail_("9: wrong exception thrown");
   }
   test_(b.find() == ULONG_MAX);
   test_(b.rfind() == ULONG_MAX);
   test_(b.substr(0) == bitstring());

   // Validate construction and to_string()
   bitstring b2(5);
   test_(b2.size() == 5);
   for (size_t i = 0; i < 5; ++i)
      test_(!b2.test(i));
   test_(b2.to_string() == "00000");

   // Test copy, assign, equality, and from_string
   bitstring b3(b2);
   test_(b2 == b3);
   test_(b != b2);
   b3.set(2);
   test_(b3.test(2));
   test_(b2 != b3);
   test_(b2.to_string() == "00000");
   b = b2;
   test_(b.to_string() == "00000");

   // Test bit ops
   bitstring x("011010110");
   bitstring savex(x);
   test_(x.count() == 5);
   test_(x.any());
   test_((x << 6).to_string() == "110000000");
   test_((x >> 6).to_string() == "000000011");
   test_((~x).to_string() == "100101001");
   test_((x <<= 3).to_string() == "010110000");
   test_((x >>= 3).to_string() == "000010110");
   x = savex;

   bitstring y("10110");
   test_(y.count() == 3);
   test_((y & x).to_string() == "001000000");
   test_((y | x).to_string() == "111110110");
   test_((y ^ x).to_string() == "110110110");
   test_((y &= x).to_string() == "00100");
   test_((y |= x).to_string() == "01101");
   test_((y ^= x).to_string() == "00000");
   test_(y.empty());
   test_(!y.any());
   y.from_string("10110111");
   test_((x &= y).to_string() == "001000110");
   test_((x |= y).to_string() == "101101110");
   test_((x ^= y).empty());
   bitstring savey = y;
   y.flip(3);
   test_(y.to_string() == "10100111");
   y.flip();
   test_(y.to_string() == "01011000");
   y.set(y.size()-1);
   test_(y.to_string() == "01011001");
   test_(y.test(y.size()-1));
   y.reset(y.size()-1);
   test_(y.to_string() == "01011000");
   y.set();
   test_(y.to_string() == "11111111");
   y.reset();
   test_(y.to_string() == "00000000");

   y = savey;
   y.resize(5);
   test_(y.to_string() == "10110");
   bitstring z(y);
   z.resize(10, true);
   test_(z.to_string() == "1011011111");

   // Test String ops
   test_((y + y).to_string() == "1011010110");
   test_((y += y).to_string() == "1011010110");
   test_((y += true).to_string() == "10110101101");
   test_(y.pop());
   test_(y.to_string() == "1011010110");
   test_(!y.pop());
   test_(y.to_string() == "101101011");
   test_(y.find() == 0);
   test_(y.find(0) == 0);
   test_(y.find(1) == 2);
   test_(y.find(1,false) == 1);
   test_(y.find(7,false) == string::npos);
   test_(y.rfind() == y.size()-1);
   test_(y.rfind(string::npos, false) == y.size()-3);
   test_(y.rfind(6) == 5);
   test_(y.rfind(6,false) == 6);
   test_(y.rfind(0,false) == string::npos);

   // Force expansion
   z = y;
   z.resize(33,true);
   test_(z.to_string() == "101101011111111111111111111111111");
   y.resize(33);
   test_(y.to_string() == "101101011000000000000000000000000");
   z.resize(20);
   test_(z.to_string() == "10110101111111111111");
   y.resize(20);
   test_(y.to_string() == "10110101100000000000");

   do_report();
}

