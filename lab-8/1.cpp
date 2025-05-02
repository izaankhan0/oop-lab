#include <iostream>

using namespace std;

class Rational {
private:
    int top;
    int bottom;

    int getGCD(int a, int b) {
        while (b != 0) {
            int holder = b;
            b = a % b;
            a = holder;
        }
        return a;
    }

    void reduce() {
        int common = getGCD(abs(top), abs(bottom));
        top /= common;
        bottom /= common;
        if (bottom < 0) {
            top = -top;
            bottom = -bottom;
        }
    }

public:
    Rational(int n = 0, int d = 1) {
        if (d == 0) {
            throw invalid_argument("Denominator cannot be zero");
        }
        top = n;
        bottom = d;
        reduce();
    }

    Rational operator+(const Rational& other) const {
        return Rational(top * other.bottom + other.top * bottom, bottom * other.bottom);
    }

    Rational operator-(const Rational& other) const {
        return Rational(top * other.bottom - other.top * bottom, bottom * other.bottom);
    }

    Rational operator*(const Rational& other) const {
        return Rational(top * other.top, bottom * other.bottom);
    }

    Rational operator/(const Rational& other) const {
        if (other.top == 0) {
            throw invalid_argument("Cannot divide by zero");
        }
        return Rational(top * other.bottom, bottom * other.top);
    }

    bool operator==(const Rational& other) const {
        return top == other.top && bottom == other.bottom;
    }

    bool operator!=(const Rational& other) const {
        return !(*this == other);
    }

    bool operator<(const Rational& other) const {
        return top * other.bottom < other.top * bottom;
    }

    bool operator>(const Rational& other) const {
        return top * other.bottom > other.top * bottom;
    }

    bool operator<=(const Rational& other) const {
        return !(*this > other);
    }

    bool operator>=(const Rational& other) const {
        return !(*this < other);
    }

    friend ostream& operator<<(ostream& out, const Rational& value) {
        out << value.top;
        if (value.bottom != 1) {
            out << "/" << value.bottom;
        }
        return out;
    }

    friend istream& operator>>(istream& in, Rational& value) {
        char sep;
        in >> value.top >> sep >> value.bottom;
        if (value.bottom == 0) {
            throw invalid_argument("Denominator cannot be zero");
        }
        value.reduce();
        return in;
    }
};

int main() {
    Rational input1, input2;
    cout << "Type two fractions like '3/4 5/6': ";
    cin >> input1 >> input2;

    cout << "\n=== Your Input ===\n";
    cout << "First: " << input1 << endl;
    cout << "Second: " << input2 << endl;

    cout << "\n=== Math Stuff ===\n";
    cout << input1 << " + " << input2 << " = " << (input1 + input2) << endl;
    cout << input1 << " - " << input2 << " = " << (input1 - input2) << endl;
    cout << input1 << " * " << input2 << " = " << (input1 * input2) << endl;
    cout << input1 << " / " << input2 << " = " << (input1 / input2) << endl;

    cout << "\n=== Comparisons ===\n";
    cout << input1 << " == " << input2 << " ? " << (input1 == input2 ? "True" : "False") << endl;
    cout << input1 << " != " << input2 << " ? " << (input1 != input2 ? "True" : "False") << endl;
    cout << input1 << " < " << input2 << " ? " << (input1 < input2 ? "True" : "False") << endl;
    cout << input1 << " > " << input2 << " ? " << (input1 > input2 ? "True" : "False") << endl;
    cout << input1 << " <= " << input2 << " ? " << (input1 <= input2 ? "True" : "False") << endl;
    cout << input1 << " >= " << input2 << " ? " << (input1 >= input2 ? "True" : "False") << endl;

    return 0;
}
