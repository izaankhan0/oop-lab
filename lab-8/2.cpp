
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Expression;

class MathToolbox {
public:
    static int compute(const Expression& expr, int value);
    static Expression getDerivative(const Expression& expr);
};

class Expression {
private:
    vector<int> terms;

    void clean() {
        while (!terms.empty() && terms.back() == 0) {
            terms.pop_back();
        }
    }

public:
    friend class MathToolbox;

    Expression() {}

    Expression(const vector<int>& inputTerms) : terms(inputTerms) {
        clean();
    }

    Expression operator+(const Expression& other) const {
        vector<int> combined(max(terms.size(), other.terms.size()), 0);
        for (size_t idx = 0; idx < terms.size(); ++idx) {
            combined[idx] += terms[idx];
        }
        for (size_t idx = 0; idx < other.terms.size(); ++idx) {
            combined[idx] += other.terms[idx];
        }
        return Expression(combined);
    }

    Expression operator-(const Expression& other) const {
        vector<int> difference(max(terms.size(), other.terms.size()), 0);
        for (size_t idx = 0; idx < terms.size(); ++idx) {
            difference[idx] += terms[idx];
        }
        for (size_t idx = 0; idx < other.terms.size(); ++idx) {
            difference[idx] -= other.terms[idx];
        }
        return Expression(difference);
    }

    Expression operator*(const Expression& other) const {
        vector<int> product(terms.size() + other.terms.size() - 1, 0);
        for (size_t i = 0; i < terms.size(); ++i) {
            for (size_t j = 0; j < other.terms.size(); ++j) {
                product[i + j] += terms[i] * other.terms[j];
            }
        }
        return Expression(product);
    }

    friend ostream& operator<<(ostream& stream, const Expression& expr) {
        if (expr.terms.empty()) {
            stream << "0";
            return stream;
        }
        bool isFirst = true;
        for (int idx = expr.terms.size() - 1; idx >= 0; --idx) {
            int val = expr.terms[idx];
            if (val == 0) continue;

            if (!isFirst) {
                stream << (val > 0 ? " + " : " - ");
            } else if (val < 0) {
                stream << "-";
            }

            int absVal = abs(val);
            if (absVal != 1 || idx == 0) {
                stream << absVal;
            }
            if (idx > 0) {
                stream << "x";
                if (idx > 1) {
                    stream << "^" << idx;
                }
            }
            isFirst = false;
        }
        return stream;
    }
};

int MathToolbox::compute(const Expression& expr, int value) {
    int output = 0;
    int multiplier = 1;
    for (int item : expr.terms) {
        output += item * multiplier;
        multiplier *= value;
    }
    return output;
}

Expression MathToolbox::getDerivative(const Expression& expr) {
    if (expr.terms.size() <= 1) {
        return Expression({0});
    }
    vector<int> derivedTerms(expr.terms.size() - 1);
    for (size_t i = 1; i < expr.terms.size(); ++i) {
        derivedTerms[i - 1] = expr.terms[i] * i;
    }
    return Expression(derivedTerms);
}

int main() {
    Expression exprA({3, 0, 2});
    Expression exprB({1, -1, 1});

    cout << endl << "=== Polynomial Computation ===" << endl;
    cout << "Expression A: " << exprA << endl;
    cout << "Expression B: " << exprB << endl;

    cout << endl << "--- Basic Arithmetic ---" << endl;
    cout << "A + B = " << (exprA + exprB) << endl;
    cout << "A - B = " << (exprA - exprB) << endl;
    cout << "A * B = " << (exprA * exprB) << endl;

    int plug = 2;
    cout << endl << "--- Evaluation ---" << endl;
    cout << "A(" << plug << ") = " << MathToolbox::compute(exprA, plug) << endl;
    cout << "B(" << plug << ") = " << MathToolbox::compute(exprB, plug) << endl;

    cout << endl << "--- Derivatives ---" << endl;
    cout << "A' = " << MathToolbox::getDerivative(exprA) << endl;
    cout << "B' = " << MathToolbox::getDerivative(exprB) << endl;

    return 0;
}
