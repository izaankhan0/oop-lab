#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
    float weight;
    float pound;
    cout << "Enter Weight in Kg: ";
    cin >> weight;

    pound = weight * 2.2;

    printf("\n Weight in Kg: %2.f", weight);
    printf("\n Weight in Pounds: %2.f", pound);

    return 0;
}
