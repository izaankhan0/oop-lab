#include <iostream>
using namespace std;

class Employee {
	double salary;
	public:
		string fname, lname;
		void setSalary(double Psalary){
			if (Psalary < 0){
				salary = 0.0;
			}else{
				salary = Psalary;
			}
		}
		
		double getSalary(){
			return salary;
		}
		
};

int main(){
	
	Employee emp1;
	Employee emp2;
	emp1.fname = "Talha";
	emp1.lname = "Mirza";
	emp2.fname = "Izaan";
	emp2.lname = "Khan";
	
	double sal1, sal2;
	
	cout << "Enter Salary of " << emp1.fname << endl;
	cin >> sal1;
	
	cout << "Enter Salary of " << emp2.fname << endl;
	cin >> sal2;
	
	emp1.setSalary(sal1);
	emp2.setSalary(sal2);
	
	cout << "Yearly Salary of Employee 1 is: " << emp1.getSalary() * 12 << endl;
	cout << "Yearly Salary of Employee 2 is: " << emp2.getSalary() * 12 << endl;
	cout << "After 10% Bonus Yearly Salary of "<< emp1.fname << " is: " << emp1.getSalary() * 12 * 0.9 << endl;
	cout << "After 10% Bonus Yearly Salary of "<< emp2.fname << " is: " << emp2.getSalary() * 12 * 0.9 << endl;
	
	
	return 0;
}