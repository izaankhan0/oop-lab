#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Car {
    string ID;
public:
    Car(string IDp) : ID(IDp) {
        cout << "Car " << ID << " Constructed" << endl;
    }
    
    ~Car() {
        cout << "Car " << ID << " Destroyed" << endl;
    }

    string getID() {
        return ID;
    }
};

class Garage {
private:
    vector<Car*> cars;
public:
    void parkCar(Car* car) {
        cars.push_back(car);
    }

    void listCars() {
        cout << "Cars in garage:\n";
        for (int i = 0; i < cars.size(); i++) {
            cout << "Car#" << i + 1 << ": " << cars[i]->getID() << endl;
        }
    }
};

int main() {
    Car car1("A123");
    Car car2("B456");

    Garage garage;
    
    garage.parkCar(&car1);
    garage.parkCar(&car2);

    garage.listCars();

    return 0;
}
