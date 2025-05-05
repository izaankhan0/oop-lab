#include <iostream>
using namespace std;

template<typename Type>
class Calculator {
protected:
    Type first, second;

public:
    Calculator(Type value1, Type value2) : first(value1), second(value2) {}

    Type computePrimary() const {
        return first * second;
    }

    void showPrimaryResult() const {
        cout << "Primary Calculation (first * second): " << computePrimary() << endl;
    }
};

template<typename Type>
class AdvancedCalculator : public Calculator<Type> {
private:
    Type third, fourth;

public:
    AdvancedCalculator(Type value1, Type value2, Type value3, Type value4)
        : Calculator<Type>(value1, value2), third(value3), fourth(value4) {}

    Type computeSecondary() const {
        return third * fourth;
    }

    void showSecondaryResult() const {
        cout << "Secondary Calculation (third * fourth): " << computeSecondary() << endl;
    }

    void showAllResults() const {
        this->showPrimaryResult();
        showSecondaryResult();
    }
};

int main() {
    try {
        AdvancedCalculator<int> task(2, 3, 4, 5);
        cout << "Computation Output:\n";
        task.showAllResults();
    } catch (const exception& err) {
        cerr << "Error occurred: " << err.what() << endl;
    }
    return 0;
}
