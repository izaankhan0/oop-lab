#include <iostream>
#include <string>

using namespace std;

// Abstract Base Class
class ShapeBase {
    public:
        virtual float CalculateArea() = 0; // Pure virtual function
};

// Derived Class A
class Box : public ShapeBase {
    private:
        float length;
        float breadth;
    public:
        Box(float l, float b) : length(l), breadth(b) {
            // Constructor with parameters
        }
        float CalculateArea() override {
            return length * breadth;
        }
};

// Derived Class B
class Pyramid : public ShapeBase {
    private:
        float baseLength;
        float heightValue;
    public:
        Pyramid(float bl, float h) : baseLength(bl), heightValue(h) {
            // Constructor with parameters
        }
        float CalculateArea() override {
            return 0.5f * baseLength * heightValue;
        }
};

int main() {
    Box b1(10.0f, 20.0f);
    Pyramid p1(18.0f, 5.0f);

    cout << "Box Area: " << b1.CalculateArea() << endl;
    cout << "Pyramid Area: " << p1.CalculateArea() << endl;

    return 0;
}
