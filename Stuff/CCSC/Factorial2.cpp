// Compile-time computation using templates.
template<int n> struct Factorial {
  enum { val = Factorial<n-1>::val * n };
};

template<> struct Factorial<0> {
  enum { val = 1 };
};

int main() {
  int n = Factorial<12>::val;
}
