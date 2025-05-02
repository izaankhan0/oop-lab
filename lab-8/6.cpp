#include <iostream>
#include <string>
using namespace std;

class Worker {
protected:
    int id;
public:
    void input() {
        cout << "Enter ID: ";
        cin >> id;
    }
    void show() {
        cout << "ID: " << id << endl;
    }
};

class Manager : public Worker {
private:
    string fullName;
    double salary;
public:
    void input() {
        Worker::input();
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, fullName);
        cout << "Enter Monthly Salary: ";
        cin >> salary;
    }

    double computeBonus() {
        return (salary * 12) * 0.05;
    }

    void show() {
        Worker::show();
        cout << "Name: " << fullName << endl;
        cout << "Monthly Salary: $" << salary << endl;
        cout << "Yearly Bonus: $" << computeBonus() << endl;
    }
};

class Finance : public Worker {
private:
    string fullName;
    double salary;
public:
    void input() {
        Worker::input();
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, fullName);
        cout << "Enter Monthly Salary: ";
        cin >> salary;
    }

    double computeBonus() {
        return (salary * 12) * 0.05;
    }

    void show() {
        Worker::show();
        cout << "Name: " << fullName << endl;
        cout << "Monthly Salary: $" << salary << endl;
        cout << "Yearly Bonus: $" << computeBonus() << endl;
    }
};

int main() {
    Manager teamLead;
    Finance accountant;

    cout << "\nEnter Manager Info:" << endl;
    teamLead.input();

    cout << "\nEnter Finance Info:" << endl;
    accountant.input();

    cout << "\nEmployee Overview:\n" << endl;

    cout << "Manager Details:" << endl;
    teamLead.show();

    cout << "\nFinance Details:" << endl;
    accountant.show();

    return 0;
}
