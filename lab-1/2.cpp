#include<iostream>
using namespace std;

int main(){
    int len;
    cout << "Enter length of the array: ";
    cin >> len;
    int array[4];

    for (int i = 0; i < len; i++)
    {
        cout << "Enter Number " << i + 1 << ": "; 
        cin >> array[i];
    }

    int sum = 0;
    
    for (int j = 0; j < len; j++)
    {
        sum += array[j];
    }

    cout << "Sum is: " << sum << endl;
    
    return 0;
}