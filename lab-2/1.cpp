#include <iostream>
using namespace std;



int main(int argCount, char *argValues[]){
    if(argCount < 2){
        cout << "InComplete Data";
        return 1;
    }

    int totalNumbers = argCount - 1;
    int* numberList = new int[totalNumbers];
    for (int index = 0; index < totalNumbers; index++){
        numberList[index] = stoi(argValues[index+1]);
    }
    int totalSum = 0;
    int* numberPtr = numberList;


    for (int index = 0; index < totalNumbers; index++){
        totalSum = totalSum + *numberPtr;
        numberPtr++;
    }


    cout << "The Sum: " << totalSum << endl;


    delete[] numberList;
    return 0;
}
