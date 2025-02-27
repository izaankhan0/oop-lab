#include <iostream>
using namespace std;

class Vehicle {
public:
    mutable int HorsePower;
    mutable int SeatCount;
    mutable int SpeakerCount;
    
    void ModifyAttributes(int power, int seats, int speakers) const {
        HorsePower = power;
        SeatCount = seats;
        SpeakerCount = speakers;
    }
    
    void ShowDetails() const {
        cout << "Horsepower: " << HorsePower << endl
             << "Seat Count: " << SeatCount << endl
             << "Speakers Installed: " << SpeakerCount << endl << endl;
    }
};

int main() {
    Vehicle Specs;
    Specs.HorsePower = 130;
    Specs.SeatCount = 20;
    Specs.SpeakerCount = 5;

    cout << "Default Specifications:" << endl;
    Specs.ShowDetails();

    Specs.ModifyAttributes(200, 5, 8);
    cout << "Updated Specifications via Constant Function:" << endl;
    Specs.ShowDetails();
    
    return 0;
}
