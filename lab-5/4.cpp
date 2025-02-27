#include <iostream>
#include <string>
#include <unistd.h>

using namespace std;

class Mixer {
public:
    void MixJuice(string fruit) {
        cout << "Mixing " << fruit << " juice..." << endl;
        for (int i = 0; i < 3; i++) {
            cout << "Processing..." << endl;
            sleep(1);
        }
        cout << "Mixing complete!" << endl;
    }
};

class Crusher {
public:
    void CrushJuice(string fruit) {
        cout << "Crushing " << fruit << " juice..." << endl;
        sleep(4);
        cout << "Crushing complete!" << endl;
    }
};

class JuiceProcessor {
private:
    Mixer mix;
    Crusher crush;

public:
    void PrepareJuice(string fruit) {
        mix.MixJuice(fruit);
        crush.CrushJuice(fruit);
        cout << fruit << " juice is now ready to serve!" << endl;
    }
};

int main() {
    string fruitType;
    cout << "Enter the fruit name to make juice: ";
    cin >> fruitType;
    JuiceProcessor machine;
    machine.PrepareJuice(fruitType);
    return 0;
}
