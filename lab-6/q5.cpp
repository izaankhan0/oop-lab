#include<iostream>
#include<vector>
using namespace std;

class Vehicles{
    protected:
        double price;
    public:
        Vehicles(double price):price(price){}

        double getPrice(){return price;}
        void setPrice(double price){ this-> price = price;}

        virtual ~Vehicles(){}
};

class Car : public Vehicles{
    protected:
        int doors;
        int seating;
        string fuel; //Diesel or Petrol
    public:
        Car(int doors, int seating, string fuel, double price): doors(doors), seating(seating), fuel(fuel), Vehicles(price){}

        virtual ~Car(){}
};
class Motorcycle : public Vehicles{
    protected:
        int cylinders;
        int gears;
        int wheels;
    public:
        Motorcycle(int cylinders, int gears, int wheels, double price): cylinders(cylinders), gears(gears), wheels(wheels), Vehicles(price){}

        virtual ~Motorcycle(){}
};

class Audi : public Car{
    string model;
    public:
        Audi(string model, int doors, int seating, string fuel, double price): model(model),Car(doors, seating, fuel, price){}

        void display(){
            cout << "Model: " << model << endl;
            cout << "Price: $" << price << endl;
            cout << "Seating Capacity: " << seating << endl;
            cout << "# of Doors: " << doors << endl;
            cout << "Fuel Type: " << fuel << endl;
        }

        virtual ~Audi(){}
};

class Yamaha : public Motorcycle{
    string make;
    public:
        Yamaha(string make, int cylinders, int gears, int wheels, double price): make(make),Motorcycle(cylinders, gears, wheels, price){}

        void display(){
            cout << "Make: " << make << endl;
            cout << "Price: $" << price << endl;
            cout << "# of wheels: " << wheels << endl;
            cout << "# of cylinders: " << cylinders << endl;
            cout << "# of gears: " << gears << endl;
        }

        virtual ~Yamaha(){}
};

int main(){


    vector<Audi*> audis;
    vector<Yamaha*> yamahas;

    audis.push_back(new Audi("A4", 4, 5, "Petrol", 45000));
    audis.push_back(new Audi("A6", 4, 5, "Diesel", 60000));
    audis.push_back(new Audi("Q5", 4, 7, "Petrol", 70000));
    audis.push_back(new Audi("R8", 2, 2, "Petrol", 150000));

    yamahas.push_back(new Yamaha("YZF-R1", 4, 6, 2, 20000));
    yamahas.push_back(new Yamaha("MT-07", 2, 6, 2, 7500));
    yamahas.push_back(new Yamaha("FZ-09", 3, 6, 2, 9000));
    yamahas.push_back(new Yamaha("R3", 2, 6, 2, 5000));

    cout << "Audi Cars:\n";
    for(int i = 0; i < audis.size(); i++){
        audis.at(i)->display();
        cout << "------------------------\n";
    }

    cout << "\nYamaha Motorcycles:\n";
    for(int i = 0; i < yamahas.size(); i++){
        yamahas.at(i)->display();
        cout << "------------------------\n";
    }

    

    for(int i = 0; i < audis.size(); i++){
        delete audis.at(i);
    }
    
    for(int i = 0; i < yamahas.size(); i++){
        delete yamahas.at(i);
    }



    return 0;
}