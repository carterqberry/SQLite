int foo()
{
   int x = 3;

   // Nested function
   int bar(int z)
   {
      return x + z;
   }
   
   int a = bar(2); // [x =] 3 + 2 = 5
   x = 5;
   int b = bar(3); // [x =] 5 + 3 = 8
   return a + b;
}

int main()
{
   printf("%d\n",foo());   // 13
   return 0;
}

