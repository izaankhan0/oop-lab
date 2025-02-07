#include <iostream>
using namespace std;

class Glass {
	
	public:
		int LiquidLevel;
		
		void Drink(int milliliters){
			LiquidLevel -= milliliters;
		}
		
		void Refill(){
			LiquidLevel = 200;
		}
};

int main(){
	
	Glass juice;
	int drink;
	juice.LiquidLevel = 200;
	
	int choice = 0;
	
	while(choice != 3){
		cout << "Press 1 to display level:"<< endl;
		cout << "Press 2 to drink:" << endl;
		cout << "Press 3 to exit:" << endl;
		
		if (juice.LiquidLevel < 100){
			juice.Refill();
			cout << "Juice has been refilled to 200" << endl;
		}
		
		cin >> choice;
		
		if(choice == 1){
			cout << "Level Currently is: " << juice.LiquidLevel << endl;
		}else if(choice == 2){
			cin >> drink;
			juice.Drink(drink);
			cout << "Level Currently is: " << juice.LiquidLevel << endl;
		}else if(choice == 3){
			
		}
		else{
			cout << "Invalid Entry";
		}
		
	}
	
	return 0;
}