#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class HugeNumber {
private:
    vector<int> digits;
    bool negative;

    void normalize() {
        while (digits.size() > 1 && digits.back() == 0)
            digits.pop_back();
        if (digits.size() == 1 && digits[0] == 0)
            negative = false;
    }

public:
    HugeNumber() : negative(false) {
        digits.push_back(0);
    }

    HugeNumber(const string& input) {
        negative = (input[0] == '-');
        int offset = (negative || input[0] == '+') ? 1 : 0;
        for (int i = input.length() - 1; i >= offset; --i)
            digits.push_back(input[i] - '0');
        normalize();
    }

    HugeNumber operator+(const HugeNumber& other) const {
        if (negative == other.negative) {
            HugeNumber result;
            result.negative = negative;
            result.digits.clear();
            int carry = 0;
            size_t limit = max(digits.size(), other.digits.size());

            for (size_t i = 0; i < limit || carry; ++i) {
                int a = (i < digits.size()) ? digits[i] : 0;
                int b = (i < other.digits.size()) ? other.digits[i] : 0;
                int total = a + b + carry;
                carry = total / 10;
                result.digits.push_back(total % 10);
            }
            result.normalize();
            return result;
        }
        return *this - (-other);
    }

    HugeNumber operator-(const HugeNumber& other) const {
        if (negative != other.negative)
            return *this + (-other);

        if (*this == other)
            return HugeNumber("0");

        bool resNeg = (*this < other);
        const HugeNumber& maxNum = resNeg ? other : *this;
        const HugeNumber& minNum = resNeg ? *this : other;

        HugeNumber result;
        result.negative = resNeg;
        result.digits.clear();

        int carry = 0;
        for (size_t i = 0; i < maxNum.digits.size(); ++i) {
            int val1 = maxNum.digits[i];
            int val2 = (i < minNum.digits.size()) ? minNum.digits[i] : 0;
            int diff = val1 - val2 - carry;
            if (diff < 0) {
                diff += 10;
                carry = 1;
            } else {
                carry = 0;
            }
            result.digits.push_back(diff);
        }
        result.normalize();
        return result;
    }

    HugeNumber operator*(const HugeNumber& other) const {
        HugeNumber result;
        result.digits.assign(digits.size() + other.digits.size(), 0);
        result.negative = (negative != other.negative);

        for (size_t i = 0; i < digits.size(); ++i) {
            int carry = 0;
            for (size_t j = 0; j < other.digits.size() || carry; ++j) {
                int val1 = digits[i];
                int val2 = (j < other.digits.size()) ? other.digits[j] : 0;
                int sum = result.digits[i + j] + val1 * val2 + carry;
                result.digits[i + j] = sum % 10;
                carry = sum / 10;
            }
        }

        result.normalize();
        return result;
    }

    HugeNumber operator-() const {
        HugeNumber flipped = *this;
        if (*this != HugeNumber("0"))
            flipped.negative = !negative;
        return flipped;
    }

    bool operator==(const HugeNumber& other) const {
        return digits == other.digits && negative == other.negative;
    }

    bool operator!=(const HugeNumber& other) const {
        return !(*this == other);
    }

    bool operator<(const HugeNumber& other) const {
        if (negative != other.negative) return negative;
        if (digits.size() != other.digits.size())
            return (digits.size() < other.digits.size()) ^ negative;
        for (int i = digits.size() - 1; i >= 0; --i) {
            if (digits[i] != other.digits[i])
                return (digits[i] < other.digits[i]) ^ negative;
        }
        return false;
    }

    bool operator>(const HugeNumber& other) const {
        return other < *this;
    }

    bool operator<=(const HugeNumber& other) const {
        return !(*this > other);
    }

    bool operator>=(const HugeNumber& other) const {
        return !(*this < other);
    }

    friend istream& operator>>(istream& in, HugeNumber& value) {
        string s;
        in >> s;
        value = HugeNumber(s);
        return in;
    }

    friend ostream& operator<<(ostream& out, const HugeNumber& value) {
        if (value.negative)
            out << "-";
        for (int i = value.digits.size() - 1; i >= 0; --i)
            out << value.digits[i];
        return out;
    }
};

int main() {
    HugeNumber a, b;
    cout << "Enter first large number: ";
    cin >> a;
    cout << "Enter second large number: ";
    cin >> b;

    cout << "Sum: " << (a + b) << endl;
    cout << "Difference: " << (a - b) << endl;
    cout << "Product: " << (a * b) << endl;
    cout << "Comparison: " << ((a > b) ? "First is greater" : "Second is greater or equal") << endl;

    return 0;
}
