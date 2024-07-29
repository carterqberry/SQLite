// integrate.d: Illustrates function delegates

// Intergrates c*x over [0,x]
double linear(double x, double c)
{
   return integrate(0.0, x,
      delegate double(double x) { return c * x; }  // A closure
   );
}

double integrate(double x1, double x2,
   double delegate(double dx) f)
{
    double sum = 0;
    double dx = 0.0001;

    for (double x = x1; x < x2; x += dx)
    {
       sum += f(x) * dx;
    }
    return sum;
}

int main()
{
   // Integral of 1.5x over [0,3]
   printf("%f\n", linear(3.0, 1.5)); // 6.749775 (~= 6.75)
   return 0;
}

