#include <iostream>
#include <string>
using namespace std;

class Traveler {
   string name;
public:
   Traveler(const string& s) : name(s) {}
   string getName() const { return name; }
};

class Pager {
   string id;
public:
   Pager(const string& s) : id(s) {}
   string getID() const { return id; }
};

class BusinessTraveler : public Traveler {
   Pager pager;
public:
   BusinessTraveler(const string& name="", const string& id="")
   : Traveler(name), pager(id) {}
   Pager getPager() const { return pager; }
   friend ostream& operator<<(ostream& os,
                              const BusinessTraveler& bt) {
      return os << '{' << bt.getName() << ','
                << bt.getPager().getID() << '}';
   }
};

int main() {
   BusinessTraveler bt("John", "P1367");
   cout << bt << endl;
}
