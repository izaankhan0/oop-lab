#include <iostream>
#include <exception>
using namespace std;

class IndexViolation : public exception {
public:
    const char* what() const noexcept override {
        return "Tried to access an invalid position in the sequence.";
    }
};

template<typename DataType>
class GuardedList {
private:
    DataType* storage;
    int length;

public:
    GuardedList(int count) : length(count) {
        if (length <= 0)
            throw invalid_argument("Length must be greater than zero.");
        storage = new DataType[length];
    }

    ~GuardedList() {
        delete[] storage;
    }

    DataType& at(int pos) {
        if (pos < 0 || pos >= length) {
            throw IndexViolation();
        }
        return storage[pos];
    }

    int count() const {
        return length;
    }

    void show() const {
        for (int i = 0; i < length; ++i) {
            cout << storage[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    try {
        GuardedList<int> numbers(5);

        for (int i = 0; i < numbers.count(); ++i) {
            numbers.at(i) = i * 10;
        }

        cout << "Sequence values: ";
        numbers.show();

        cout << "\nLooking at position 2:\n";
        cout << numbers.at(2) << endl << endl;

        cout << "Now accessing position 10...\n";
        cout << numbers.at(10) << endl;

    } catch (const IndexViolation& err) {
        cerr << "Issue: " << err.what() << endl;
    } catch (const exception& ex) {
        cerr << "Other issue: " << ex.what() << endl;
    }

    return 0;
}
