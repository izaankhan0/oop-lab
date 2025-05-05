#include <iostream>
#include <any>
#include <exception>
using namespace std;

class InvalidTypeAccess : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid type access detected.";
    }
};

class FlexibleBox {
private:
    any item;

public:
    template <typename T>
    void put(const T& value) {
        item = value;
    }

    template <typename T>
    T fetch() const {
        try {
            return any_cast<T>(item);
        } catch (const bad_any_cast&) {
            throw InvalidTypeAccess();
        }
    }
};

int main() {
    try {
        FlexibleBox box;

        box.put(100);
        int number = box.fetch<int>();
        cout << "Number stored: " << number << endl;

        box.put(string("Hello there!"));
        string greeting = box.fetch<string>();
        cout << "Message stored: " << greeting << endl;

        double amount = box.fetch<double>();
        cout << "Value stored: " << amount << endl;

    } catch (const exception& ex) {
        cout << "Exception occurred: " << ex.what() << endl;
    }

    return 0;
}
