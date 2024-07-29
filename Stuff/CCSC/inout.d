// inout.d: Illustrates in-out parameters
void ham()
{
   int x = 1, y = 2, z = 3;

	eggs(x, y, z);
   printf("x=%d, y=%d, z=%d\n", x, y, z); // 1, 4, 9
}

void eggs(int a, out int b, inout int c)
{
	a += 1;	// x is not affected
	b  = 4;	// y is set to 4
	c *= 3;	// z is set to 9
}

int main() {
   ham();
   return 0;
}

