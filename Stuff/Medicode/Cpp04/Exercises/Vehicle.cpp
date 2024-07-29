#include <iostream>
using namespace std;

class Vehicle {
protected:
   int id;
public:
   Vehicle(int id) {
      cout << "Constructing vehicle #" << id << endl;
      this->id = id;
   }
   virtual ~Vehicle() {
      cout << "Destroying Vehicle #" << id << endl;
   }
   virtual void stop() = 0;
   virtual void go() = 0;
};

class Car : public Vehicle {
public:
   Car(int id) : Vehicle(id) {
      cout << "Constructing car #" << id << endl;
   }
   ~Car() {
      cout << "Destroying car# " << id << endl;
   }
   void stop() {
      cout << "Stopping car #" << id << endl;
   }
   void go() {
      cout << "Car #" << id << " going\n";
   }
};

class Truck : public Vehicle {
public:
   Truck(int id) : Vehicle(id) {
      cout << "Constructing Truck #" << id << endl;
   }
   ~Truck() {
      cout << "Destroying Truck# " << id << endl;
   }
   void stop() {
      cout << "Stopping Truck #" << id << endl;
   }
   void go() {
      cout << "Truck #" << id << " going\n";
   }
};

class SUV : public Vehicle {
public:
   SUV(int id) : Vehicle(id) {
      cout << "Constructing SUV #" << id << endl;
   }
   ~SUV() {
      cout << "Destroying SUV# " << id << endl;
   }
   void stop() {
      cout << "Stopping SUV #" << id << endl;
   }
   void go() {
      cout << "SUV #" << id << " going\n";
   }
};

void doVehicleStuff(Vehicle* stuffPtrs[], int nPtrs) {
   for (int i = 0; i < nPtrs; ++i) {
      stuffPtrs[i]->go();
      stuffPtrs[i]->stop();
      delete stuffPtrs[i];
   }
}

int main() {
   Vehicle* stuff[] = {new Car(10), new Truck(20),
      new SUV(30)};
   doVehicleStuff(stuff, 3);
}
