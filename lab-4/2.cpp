#include <iostream>
#include <cmath>
using namespace std;

class Polynomial{
	private:
		double *coeffArray;
		int polyDegree;
	public:
		Polynomial() : polyDegree(0){	// Default Constructor
			coeffArray = new double[1];
			coeffArray[0] = 0.0;
		}
		
		Polynomial(int deg, const double coeffs[]) : polyDegree(deg){	// Parameterized Constructor
			coeffArray = new double[deg + 1];
			for (int i = 0; i <= deg; i++){
				coeffArray[i] = coeffs[i];
			}
		}
		
		Polynomial(const Polynomial& other) : polyDegree(other.polyDegree){ // Copy Constructor
			coeffArray = new double[polyDegree + 1];
			for (int i = 0; i <= polyDegree; i++){
				coeffArray[i] = other.coeffArray[i];
			}
		}
		
		Polynomial(Polynomial&& other) noexcept : polyDegree(other.polyDegree), coeffArray(other.coeffArray) { // Move Constructor
	        other.coeffArray = nullptr;
	        other.polyDegree = 0;
	    }
	    
	    ~Polynomial(){ // Destructor
	    	delete[] coeffArray;
		}
		
		int getDegree() const{
			return polyDegree;
		}
		double evaluate(double x) const{
			double result = 0.0;
			for (int i = 0; i <= polyDegree; i++){
				result += coeffArray[i] * pow(x, i);
			}
			return result;
		}
		Polynomial add(const Polynomial& other) const {
			int maxDegree = max(polyDegree, other.polyDegree);
			double* resultCoeffs = new double[maxDegree + 1];
	
			for (int i = 0; i <= maxDegree; ++i) {
				double coeff1 = (i <= polyDegree) ? coeffArray[i] : 0.0;
				double coeff2 = (i <= other.polyDegree) ? other.coeffArray[i] : 0.0;
				resultCoeffs[i] = coeff1 + coeff2;
			}
			Polynomial result(maxDegree, resultCoeffs);
			delete[] resultCoeffs;
			return result;
		}
		Polynomial multiply(const Polynomial& other) const {
			int resultDegree = polyDegree + other.polyDegree;
			double* resultCoeffs = new double[resultDegree + 1]();
	
			for (int i = 0; i <= polyDegree; ++i) {
				for (int j = 0; j <= other.polyDegree; ++j) {
					resultCoeffs[i + j] += coeffArray[i] * other.coeffArray[j];
				}
			}
			Polynomial result(resultDegree, resultCoeffs);
			delete[] resultCoeffs;	
			return result;
		}
		void print() const {
			for (int i = polyDegree; i >= 0; --i) {
				cout << coeffArray[i];
				if (i != 0) {
					cout << "x^" << i << " + ";
				}
			}
			cout << endl;
		}
};

int main(){
	double coeffs1[] = {1.0, 2.0, 3.0}; // 1 + 2x + 3x^2
    Polynomial poly1(2, coeffs1);
	cout << "Initializing poly1" << endl;
	cout << "Polynomial poly1: ";
    poly1.print();

    cout << endl << endl <<"Copying poly1 to poly2" << endl;
    Polynomial poly2 = poly1;
    cout << "Polynomial poly2 (copy of poly1): ";
    poly2.print();

    cout << endl << endl <<"Moving poly1 to poly3" << endl;
    Polynomial poly3 = move(poly1);
    cout << "Polynomial poly3 (moved from poly1): ";
    poly3.print();

	cout << endl << endl <<"Evaluate poly3 at x = 2" << endl;
    cout << "poly3 evaluated at x = 2: " << poly3.evaluate(2) << endl;

	cout << endl << endl <<"Add poly2 and poly3" << endl;
    Polynomial poly4 = poly2.add(poly3);
    cout << "Polynomial poly4 (poly2 + poly3): ";
    poly4.print();

	cout << endl << endl <<"Multiplying poly2 and poly3" << endl;
    Polynomial poly5 = poly2.multiply(poly3);
    cout << "Polynomial poly5 (poly2 * poly3): ";
    poly5.print();
	return 0;
}
