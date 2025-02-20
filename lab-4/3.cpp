#include <iostream>
#include <cmath>
using namespace std;

class Expression{
	private:
		double *coeffList;
		int degree;
	public:
		Expression() : degree(0){
			coeffList = new double[1];
			coeffList[0] = 0.0;
		}

		Expression(int deg, const double coeffs[]) : degree(deg){
			coeffList = new double[deg + 1];
			for (int i = 0; i <= deg; i++){
				coeffList[i] = coeffs[i];
			}
		}

		Expression(const Expression& other) : degree(other.degree){
			coeffList = new double[degree + 1];
			for (int i = 0; i <= degree; i++){
				coeffList[i] = other.coeffList[i];
			}
		}

		Expression(Expression&& other) noexcept : degree(other.degree), coeffList(other.coeffList) {
			other.coeffList = nullptr;
			other.degree = 0;
		}

		~Expression(){
			delete[] coeffList;
		}

		int getDegree() const{
			return degree;
		}

		double evaluate(double x) const{
			double outcome = 0.0;
			for (int i = 0; i <= degree; i++){
				outcome += coeffList[i] * pow(x, i);
			}
			return outcome;
		}

		Expression add(const Expression& other) const {
			int maxDeg = max(degree, other.degree);
			double* resultCoeff = new double[maxDeg + 1];
			for (int i = 0; i <= maxDeg; ++i) {
				double term1 = (i <= degree) ? coeffList[i] : 0.0;
				double term2 = (i <= other.degree) ? other.coeffList[i] : 0.0;
				resultCoeff[i] = term1 + term2;
			}
			Expression outcome(maxDeg, resultCoeff);
			delete[] resultCoeff;
			return outcome;
		}

		Expression multiply(const Expression& other) const {
			int resultDeg = degree + other.degree;
			double* resultCoeff = new double[resultDeg + 1]();
			for (int i = 0; i <= degree; ++i) {
				for (int j = 0; j <= other.degree; ++j) {
					resultCoeff[i + j] += coeffList[i] * other.coeffList[j];
				}
			}
			Expression outcome(resultDeg, resultCoeff);
			delete[] resultCoeff;
			return outcome;
		}

		void display() const {
			for (int i = degree; i >= 0; --i) {
				cout << coeffList[i];
				if (i != 0) {
					cout << "x^" << i << " + ";
				}
			}
			cout << endl;
		}
};

int main(){
	double values1[] = {1.0, 2.0, 3.0};
	Expression expr1(2, values1);
	cout << "Initializing expr1" << endl;
	cout << "Expression expr1: ";
	expr1.display();

	cout << endl << "Copying expr1 to expr2" << endl;
	Expression expr2 = expr1;
	cout << "Expression expr2 (copy of expr1): ";
	expr2.display();

	cout << endl << "Moving expr1 to expr3" << endl;
	Expression expr3 = move(expr1);
	cout << "Expression expr3 (moved from expr1): ";
	expr3.display();

	cout << endl << "Evaluate expr3 at x = 2" << endl;
	cout << "expr3 evaluated at x = 2: " << expr3.evaluate(2) << endl;

	cout << endl << "Adding expr2 and expr3" << endl;
	Expression expr4 = expr2.add(expr3);
	cout << "Expression expr4 (expr2 + expr3): ";
	expr4.display();

	cout << endl << "Multiplying expr2 and expr3" << endl;
	Expression expr5 = expr2.multiply(expr3);
	cout << "Expression expr5 (expr2 * expr3): ";
	expr5.display();

	return 0;
}