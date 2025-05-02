#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string scramble(const string& original) {
    string altered = original;
    for (size_t i = 0; i < original.length(); ++i) {
        altered[i] = original[i] + (i + 1);
    }
    return altered;
}

string unscramble(const string& scrambled) {
    string restored = scrambled;
    for (size_t i = 0; i < scrambled.length(); ++i) {
        restored[i] = scrambled[i] - (i + 1);
    }
    return restored;
}

int main() {
    string message;
    cout << "Type something: ";
    getline(cin, message);

    string coded = scramble(message);

    ofstream writer("datafile.txt");
    if (!writer) {
        cerr << "Failed to create file!" << endl;
        return 1;
    }
    writer << coded;
    writer.close();

    cout << "\nOriginal Input: " << message << endl;
    cout << "Encrypted and saved: " << coded << endl;

    ifstream reader("datafile.txt");
    if (!reader) {
        cerr << "Failed to open file!" << endl;
        return 1;
    }

    string readContent;
    getline(reader, readContent);
    reader.close();

    string decoded = unscramble(readContent);
    cout << "Recovered and decrypted: " << decoded << endl;

    return 0;
}
