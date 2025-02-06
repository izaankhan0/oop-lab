#include <iostream>
#include <cstring>
using namespace std;

void ExpandArray(int*& dataCollection, int& currentCapacity, int newCapacity) {
    int* updatedCollection = new int[newCapacity];
    memcpy(updatedCollection, dataCollection, currentCapacity * sizeof(int));
    delete[] dataCollection;
    dataCollection = updatedCollection;
    currentCapacity = newCapacity;
}

int main(int argQuantity, char* argValues[]) {
    if (argQuantity < 2) {
        cout << "Not Enough Input";
    }

    int startingLimit = 5;
    int presentLimit = startingLimit;
    int* numericArray = new int[presentLimit];

    if (argQuantity - 1 > startingLimit) {
        presentLimit = startingLimit * 2;
        ExpandArray(numericArray, presentLimit, presentLimit);
        cout << "Array Expanded To " << presentLimit << " Items." << endl;
    }

    for (int index = 0; index < argQuantity - 1; index++) {
        numericArray[index] = stoi(argValues[index+1]);
    }

    if (argQuantity - 1 < presentLimit) {
        ExpandArray(numericArray, presentLimit, argQuantity - 1);
        cout << "Array changed to " << argQuantity - 1 << " items" << endl;
    }

    cout << "Modified Collection: " << endl;
    cout << "Items = [";
    for (int index = 0; index < argQuantity - 1; index++) {
        cout << numericArray[index];
        if (index < argQuantity - 2) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
    delete[] numericArray;

    return 0;
}