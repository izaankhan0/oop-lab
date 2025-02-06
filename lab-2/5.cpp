#include <iostream>
#include <vector>
using namespace std;

struct Individual {
    int Identifier;
    string FullName;
};

void ArrangeByID(vector<Individual>& Group) {
    int Total = Group.size();
    for (int i = 0; i < Total - 1; i++) {
        for (int j = 0; j < Total - i - 1; j++) {
            if (Group[j].Identifier > Group[j + 1].Identifier) {
                Individual Temp = Group[j];
                Group[j] = Group[j + 1];
                Group[j + 1] = Temp;
            }
        }
    }
}

void ArrangeByName(vector<Individual>& Group) {
    int Total = Group.size();
    for (int i = 0; i < Total - 1; i++) {
        for (int j = 0; j < Total - i - 1; j++) {
            if (Group[j].FullName[0] > Group[j + 1].FullName[0]) {
                Individual Temp = Group[j];
                Group[j] = Group[j + 1];
                Group[j + 1] = Temp;
            }
        }
    }
}

int main(int paramCount, char* paramValues[]) {
    int EntryCount = stoi(paramValues[1]);

    if (paramCount != (2 + 2 * EntryCount)) {
        cout << "Incorrect Number of Inputs! Expected " << 2 + 2 * EntryCount << " Inputs." << endl;
        return 1;
    }

    vector<Individual> Group;

    for (int i = 0; i < EntryCount; i++) {
        Individual Details;
        Details.Identifier = stoi(paramValues[2 + 2 * i]);
        Details.FullName = paramValues[2 + 2 * i + 1];
        Group.push_back(Details);
    }

    ArrangeByID(Group);
    cout << "Sorted by Identifier:" << endl;
    for (const auto& Details : Group) {
        cout << "Identifier: " << Details.Identifier << ", Full Name: " << Details.FullName << endl;
    }

    ArrangeByName(Group);
    cout << "\nSorted By First Letter of Name:" << endl;
    for (const auto& Details : Group) {
        cout << "Identifier: " << Details.Identifier << ", Full Name: " << Details.FullName << endl;
    }
    return 0;
}
