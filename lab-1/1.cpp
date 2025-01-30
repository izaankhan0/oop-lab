#include<iostream>
using namespace std;

int main(){
    int rep = 20;
    float array[20];

    for (int i = 0; i < rep; i++)
    {
        cout << "Enter Number " << i + 1 << ": "; 
        cin >> array[i];

    }

    float max_num = array[0];
    float second_max_num = array[0];
    
    for (int j = 0; j < rep; j++)
    {
        if (array[j] > max_num)
        {
            second_max_num = max_num;
            max_num = array[j];
        }
    }

    cout << "Second Max Number is: " << second_max_num << endl;
    
    return 0;
}
