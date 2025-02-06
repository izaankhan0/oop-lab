#include <iostream>
#include <vector>
using namespace std;



struct Course {
    string Title;
};
struct Learner {
    int RollNumber;
    Course Subjects[3];
};



int main(int paramCount, char* paramValues[]) {


    if (paramCount < 2){
        cout << "Insufficient Input Provided!";
    }



    int TotalLearners = stoi(paramValues[1]);
    vector<Learner> Records(TotalLearners);
    for (int i = 0; i < TotalLearners; i++){
        Records[i].RollNumber = i + 1;
        Records[i].Subjects[0].Title = "Literature";
        Records[i].Subjects[1].Title = "Native Language";
        Records[i].Subjects[2].Title = "Arithmetic";
    }
    for (const auto& i : Records) {
        cout << "Learner Roll Number: " << i.RollNumber << endl;
        for (int j = 0; j < 3; j++){
            cout << "Course " << j + 1 << ": " << i.Subjects[j].Title << endl;
        }
    }
    return 0;
}
