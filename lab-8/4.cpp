#include <iostream>

using namespace std;

class Integer {
private:
    int data;
public:
    Integer(int init) : data(init) {}

    Integer& operator--() {
        data *= 4;
        return *this;
    }

    Integer operator--(int) {
        Integer snapshot = *this;
        data /= 4;
        return snapshot;
    }

    void show() const {
        cout << "Current Value: " << data << endl;
    }
};

int main() {
    Integer number(16);

    cout << "Starting Value: ";
    number.show();

    --number;
    cout << "After Prefix (--number): ";
    number.show();

    number--;
    cout << "After Postfix (number--): ";
    number.show();

    return 0;
}
