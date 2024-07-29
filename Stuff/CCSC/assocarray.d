// assocarray.d: Associative arrays

import std.stdio;

int main() {
   int[ char[] ] keywords;
   keywords["foo"] = 3;
   keywords["bar"] = 2;
   keywords["baz"] = 1;
   
   char[] abc = "foo";
   assert(keywords[abc] == 3);
   abc = "bar";
   assert(keywords[abc] == 2);
   printf("keywords has %d elements\n", keywords.length);
   printf("keywords occupies %d bytes\n", keywords.sizeof);
   
   foreach (char[] kwd, int value; keywords)
   {
   	writefln(kwd, " = ", value);
   }
   return 0;
}

/* Output (in key order!):
keywords has 3 elements
keywords occupies 8 bytes
baz = 1
bar = 2
foo = 3
*/

