#include <iostream>
using namespace std;



void* IncreaseValues(void* numberSeries, void* count, void* increment){ int* numericSet = static_cast<int*>(numberSeries); int totalEntries = *static_cast<int*>(count); int valueIncrease = *static_cast<int*>(increment);

    for (int index = 0; index < totalEntries; index++){ numericSet[index] += valueIncrease; }
    return static_cast<void*>(numericSet);
}

int main(int argumentTotal, char *argumentList[]){ if(argumentTotal < 3){ cout << "Provided Information is Incomplete!!"; return 1; }

    int increaseAmount = stoi(argumentList[1]); int elementCount = argumentTotal - 1; int* dataSet = new int[elementCount];
    for (int index = 0; index < elementCount; index++){ dataSet[index] = stoi(argumentList[index+1]); }
    void* processedData = IncreaseValues(static_cast<void*>(dataSet), static_cast<void*>(&elementCount), static_cast<void*>(&increaseAmount)); 

    int* finalNumbers = static_cast<int*>(processedData);

    cout << "Updated Numbers After Adding " << increaseAmount << " To Every Value: "<< endl;
    for (int index = 0; index < elementCount; index++){ cout << finalNumbers[index] << " "; }
    cout << endl;

    delete[] dataSet; return 0;
}
