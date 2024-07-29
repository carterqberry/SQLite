// arrays.cpp: Illustrates dynamic arrays and slicing

int main() {	
   char[] t = "hello";
   foreach (int i, char c; t)
	{
	    printf("a[%d] = %c ", i, c);
	}
   printf("\n");
   
   char[] s;
   s.length = 7;
	s[] = 'c';				// fill
   foreach (int i, char c; s)
	{
	    printf("s[%d] = %c ", i, c);
	}
   printf("\n");
   
	s[2..4] = t[0..2];	// substring copy
   foreach (int i, char c; s)
	{
	    printf("s[%d] = %c ", i, c);
	}
   return 0;
}

