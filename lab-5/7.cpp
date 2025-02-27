#include <iostream>
#include <string>
using namespace std;

class Learner {
private:
    const int RegNumber;
    string FullName;
public:
    Learner(int regID, string lName) : RegNumber(regID), FullName(lName) {}
    void ShowDetails() const {
        cout << "Registration Number: " << RegNumber << endl;
        cout << "Full Name: " << FullName << endl;
    }
};

int main() {
    int regID;
    string lName;
    
    cout << "Enter Full Name: ";
    getline(cin, lName);
    cout << "Enter Registration ID: ";
    cin >> regID;
    
    Learner StudentProfile(regID, lName);
    
    cout << "\nProfile Summary:" << endl;
    StudentProfile.ShowDetails();
    
    return 0;
}
