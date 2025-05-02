#include <iostream>
using namespace std;

class Rectangle {
private:
    double length, width;

public:
    Rectangle(double l = 0, double w = 0) : length(l), width(w) {}

    double computeArea() const {
        return length * width;
    }

    Rectangle operator+(const Rectangle& rhs) const {
        double combined = this->computeArea() + rhs.computeArea();
        return Rectangle(combined, 1);
    }

    void showArea() const {
        cout << "Area: " << computeArea() << endl;
    }
};

int main() {
    Rectangle box1(5, 4);
    Rectangle box2(3, 6);

    cout << "Box 1 ";
    box1.showArea();

    cout << "Box 2 ";
    box2.showArea();

    Rectangle result = box1 + box2;

    cout << "Combined ";
    result.showArea();

    return 0;
}
