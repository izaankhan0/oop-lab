#include <iostream>
using namespace std;

class User {
	public:
		int Age;
		string Name;
};

int main(){
	
	User User1;
	User1.Name = "Teo";
	User1.Age = 24;
	
	cout << "My name is " << User1.Name << " and I'm " << User1.Age << " years old.";
	
	return 0;
}