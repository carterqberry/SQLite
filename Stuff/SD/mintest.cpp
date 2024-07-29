template<class T>
T min(const T& t1, const T& t2) {
   return t1 < t2 ? t1 : t2;
}

int main() {
   int x = min<double>(1,20.0);
   int y = min(1.0, 20);
}
