#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

const string dataFile = "tasks.txt";

vector<string> fetchAllEntries() {
    vector<string> entryList;
    ifstream input(dataFile);
    string contentLine;

    while (getline(input, contentLine)) {
        entryList.push_back(contentLine);
    }

    input.close();
    return entryList;
}

void showEntries() {
    vector<string> entries = fetchAllEntries();

    if (entries.empty()) {
        cout << "Nothing to show." << endl;
        return;
    }

    cout << "\nCurrent List:" << endl;
    for (size_t index = 0; index < entries.size(); ++index) {
        cout << index + 1 << ". " << entries[index] << endl;
    }
    cout << endl;
}

void insertEntry(const string& entryText) {
    ofstream output(dataFile, ios::app);
    if (!output) {
        cerr << "Unable to write to file." << endl;
        return;
    }

    output << "[ ] " << entryText << endl;
    output.close();
    cout << "New entry saved." << endl;
}

void completeEntry(int entryId) {
    vector<string> currentEntries = fetchAllEntries();

    if (entryId < 1 || entryId > (int)currentEntries.size()) {
        cout << "No entry at that number." << endl;
        return;
    }

    if (currentEntries[entryId - 1].substr(0, 3) == "[ ]") {
        currentEntries[entryId - 1].replace(0, 3, "[x]");
    } else {
        cout << "Already completed." << endl;
        return;
    }

    ofstream output(dataFile);
    for (const string& item : currentEntries) {
        output << item << endl;
    }

    cout << "Marked as complete." << endl;
}

int main() {
    int userOption;
    string newEntry;
    int entryNumber;

    do {
        cout << "===== Personal List Manager =====" << endl;
        cout << "1. Show Items" << endl;
        cout << "2. Add Item" << endl;
        cout << "3. Complete Item" << endl;
        cout << "0. Quit" << endl;
        cout << "Select option: ";
        cin >> userOption;
        cin.ignore();

        switch (userOption) {
            case 1:
                showEntries();
                break;
            case 2:
                cout << "Type your item: ";
                getline(cin, newEntry);
                insertEntry(newEntry);
                break;
            case 3:
                showEntries();
                cout << "Pick item number to complete: ";
                cin >> entryNumber;
                completeEntry(entryNumber);
                break;
            case 0:
                cout << "Goodbye." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }

    } while (userOption != 0);

    return 0;
}
