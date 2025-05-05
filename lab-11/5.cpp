#include <iostream>
#include <vector>
#include <exception>
using namespace std;

class EmptyStackError : public exception {
public:
    const char* what() const noexcept override {
        return "Error: No items left in the stack.";
    }
};

template <typename Type>
class NumberStack {
private:
    vector<Type> elements;

public:
    void add(const Type& item) {
        elements.push_back(item);
    }

    void remove() {
        if (elements.empty()) {
            throw EmptyStackError();
        }
        elements.pop_back();
    }

    Type peek() const {
        if (elements.empty()) {
            throw EmptyStackError();
        }
        return elements.back();
    }

    bool isEmpty() const {
        return elements.empty();
    }

    void show() const {
        cout << "Current Stack: ";
        for (auto it = elements.rbegin(); it != elements.rend(); ++it) {
            cout << *it << " ";
        }
        cout << endl;
    }
};

int main() {
    NumberStack<int> numbers;

    try {
        cout << "Adding data to stack...\n";
        numbers.add(10);
        numbers.add(20);
        numbers.add(30);

        numbers.show();

        cout << "Top value: " << numbers.peek() << endl;

        cout << "Removing items...\n";
        numbers.remove();
        numbers.remove();

        numbers.show();
        cout << "Top value: " << numbers.peek() << endl;

        cout << "Removing last item...\n";
        numbers.remove();

        cout << "\nNow attempting invalid removal...\n";
        numbers.remove();

    } catch (const EmptyStackError& err) {
        cerr << "Exception caught: " << err.what() << endl;
    }

    try {
        cout << "\nTrying to peek into empty stack...\n";
        cout << "Peek result: " << numbers.peek() << endl;
    } catch (const EmptyStackError& err) {
        cerr << "Exception caught: " << err.what() << endl;
    }

    return 0;
}
