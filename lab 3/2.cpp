#include <iostream>
using namespace std;

class Data {
	
	public:
		
		int month, day, year;
		
		int displayDate(){
			cout << day << " / " << month << " / " << year;
			return 1;
		}
};

int main(){
	
	Data valentine;
	valentine.day = 14;
	valentine.month = 2;
	valentine.year = 2025;
	valentine.displayDate();
	
	return 0;
}