#include <iostream>
#include <string>
using namespace std;

template<class T>
T maxf(const T& t1, const T& t2) {
   return (t1 > t2) ? t1 : t2;
}

template<class T>
T minf(const T& t1, const T& t2) {
   return (t1 < t2) ? t1 : t2;
}

class Person {
   string name;
   int age;
public:
   Person(const string& s, int a)
     : name(s), age(a)
   {}
   friend bool operator>(const Person& p1, const Person& p2);
   friend bool operator<(const Person& p1, const Person& p2);
   friend ostream& operator<<(ostream& os, const Person& p);
};

bool operator>(const Person& p1, const Person& p2) {
   return p1.age > p2.age;
}
bool operator<(const Person& p1, const Person& p2) {
   return p1.age < p2.age;
}
ostream& operator<<(ostream& os, const Person& p) {
   return os << '{' << p.name << ',' << p.age << '}';
}

int main() {
   cout << maxf(1,2) << endl;
   cout << maxf<double>(1,2.0) << endl;
   string s1("one"), s2("two");
   cout << maxf(s1,s2) << endl;
   Person p1("John", 37), p2("Jane",47);
   cout << maxf(p1,p2) << endl;
   cout << minf(p1,p2) << endl;
}
