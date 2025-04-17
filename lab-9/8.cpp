#include <iostream>
#include <string>

using namespace std;

// Abstract Base Class
class Scholar {
public:
    virtual double CalculateFees(const string& EnrollmentType, int CourseHours) = 0;
    virtual ~Scholar() {}
};

// Derived Class: Postgraduate
class Postgraduate : public Scholar {
    private:
        string ThesisSubject;
    public:
        // Setter and Getter
        void SetThesisSubject(const string& Subject) { ThesisSubject = Subject; }
        string GetThesisSubject() const { return ThesisSubject; }

        double CalculateFees(const string& EnrollmentType, int CourseHours) override {
            double HourlyRate = 0;
            if (EnrollmentType == "undergraduate") {
                HourlyRate = 220;
            } else if (EnrollmentType == "postgraduate") {
                HourlyRate = 320;
            } else if (EnrollmentType == "doctoral") {
                HourlyRate = 450;
            } else {
                cout << "Invalid enrollment type!" << endl;
                return 0.0;
            }
            return HourlyRate * CourseHours;
        }
};

int main() {
    Postgraduate GradScholar;

    string EnrollmentType;
    int CourseHours;
    string ThesisSubject;

    cout << "--- Postgraduate Tuition Fee Calculator ---" << endl;

    cout << "Enter Enrollment Type (undergraduate / postgraduate / doctoral): ";
    getline(cin, EnrollmentType);

    cout << "Enter Number of Course Hours: ";
    cin >> CourseHours;
    cin.ignore(); // Clear newline character

    cout << "Enter Thesis Subject: ";
    getline(cin, ThesisSubject);

    GradScholar.SetThesisSubject(ThesisSubject);

    double TuitionFees = GradScholar.CalculateFees(EnrollmentType, CourseHours);

    cout << "\n--- Fee Breakdown ---" << endl;
    cout << "Thesis Subject: " << GradScholar.GetThesisSubject() << endl;
    cout << "Enrollment Type: " << EnrollmentType << endl;
    cout << "Course Hours: " << CourseHours << endl;
    cout << "Total Tuition Fees: $" << TuitionFees << endl;

    return 0;
}
