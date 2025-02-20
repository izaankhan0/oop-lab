#include <iostream>
#include <stdexcept>
using namespace std;

class Sphere {
private:
    double radiusValue;
	const double PI_VAL = 3.14159265358979323846;
public:
	Sphere(){
		radiusValue = 0;
	}
    Sphere(double inputRadius) : radiusValue(inputRadius) {
        if (inputRadius < 0) {
            throw invalid_argument("Radius cannot be a negative value.");
        }
    }
    double computeArea() const {
        return PI_VAL * radiusValue * radiusValue;
    }
    double computePerimeter() const {
        return 2 * PI_VAL * radiusValue;
    }
};

int main(int argCount, char *argValues[]) {
	if (argCount < 2) {
        cerr << "Error: Please Provide the Radius!!" << endl;
        return 1;
    }
	try{
		double radiusValue = stod(argValues[1]);
		Sphere sphereObject(radiusValue);
		
		cout.precision(3);
		cout << "Area of the sphere: " << fixed << sphereObject.computeArea() << endl;
		cout << "Perimeter of the sphere: " << fixed << sphereObject.computePerimeter() << endl;

	}catch(const invalid_argument& exception){
		cerr << exception.what() << endl;
		return 1;
	}
    return 0;
}
