#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main() {
    string firstName, lastName;
    float score1, score2, score3, score4, score5;

    cin >> firstName >> lastName;
    cin >> score1 >> score2 >> score3 >> score4 >> score5;

    float average = (score1 + score2 + score3 + score4 + score5) / 5;

    cout << "Student name: " << firstName << " " << lastName << endl;
    printf("Test scores: %.2f %.2f %.2f %.2f %.2f\n", score1, score2, score3, score4, score5);
    printf("Average test score: %.2f\n", average);

    return 0;
}
