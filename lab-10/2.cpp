#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Staff {
public:
    int code;
    string fullName;
    string role;
    int experience;

    Staff() {}

    Staff(int id, string name, string position, int yrs)
        : code(id), fullName(name), role(position), experience(yrs) {}

    string serialize() const {
        return to_string(code) + "," + fullName + "," + role + "," + to_string(experience);
    }

    static Staff parse(const string& row) {
        stringstream parser(row);
        string part;
        vector<string> data;

        while (getline(parser, part, ',')) {
            data.push_back(part);
        }

        return Staff(stoi(data[0]), data[1], data[2], stoi(data[3]));
    }
};

class FileEditor {
private:
    string dbPath;

public:
    FileEditor(const string& path) : dbPath(path) {}

    void seedFile() {
        ofstream file(dbPath);
        if (!file) {
            cerr << "Unable to open file for writing!" << endl;
            return;
        }

        vector<Staff> sample = {
            {1, "Liam West", "engineer", 3},
            {2, "Ava Brooks", "manager", 5},
            {3, "Noah Gray", "analyst", 1},
            {4, "Mia Stone", "manager", 2},
            {5, "Ethan Ray", "technician", 1}
        };

        for (const auto& person : sample) {
            file << person.serialize() << endl;
        }

        file.close();
        cout << "Sample staff records created.\n";
    }

    vector<Staff> loadAll() {
        vector<Staff> list;
        ifstream file(dbPath);
        string line;

        while (getline(file, line)) {
            if (!line.empty()) {
                list.push_back(Staff::parse(line));
            }
        }

        file.close();
        return list;
    }

    void overwrite(const vector<Staff>& list) {
        ofstream file(dbPath);
        for (const auto& person : list) {
            file << person.serialize() << endl;
        }
        file.close();
    }

    vector<Staff> fetchManagers(int minYears = 2) {
        vector<Staff> result;
        vector<Staff> all = loadAll();

        for (const auto& person : all) {
            if (person.role == "manager" && person.experience >= minYears) {
                result.push_back(person);
            }
        }

        return result;
    }

    void retainOnly(const vector<Staff>& selected) {
        overwrite(selected);
        cout << "Database cleaned to keep only selected entries.\n";
    }

    void reindexAndUpdate(const vector<Staff>& original) {
        vector<Staff> refreshed;
        int id = 1;

        for (auto record : original) {
            record.code = id++;
            record.experience += 1;
            refreshed.push_back(record);
        }

        overwrite(refreshed);
        cout << "Reindexed and updated records written to file.\n";
    }
};

int main() {
    FileEditor storage("stafflist.txt");

    storage.seedFile();

    cout << "Query: Managers with 2+ years:\n";
    vector<Staff> managers = storage.fetchManagers();

    for (const auto& m : managers) {
        cout << m.serialize() << endl;
    }

    storage.retainOnly(managers);

    storage.reindexAndUpdate(managers);

    return 0;
}
