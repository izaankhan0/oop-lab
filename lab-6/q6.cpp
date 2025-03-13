#include <iostream>
#include <vector>
using namespace std;

class Student
{
protected:
    string name;
    int rollNo;
    string department;

public:
    Student(string name, int rollNo, string department)
        : name(name), rollNo(rollNo), department(department) {}

    void displayStudentInfo()
    {
        cout << "Student Name: " << name << endl;
        cout << "Roll Number: " << rollNo << endl;
        cout << "Department: " << department << endl;
    }
};

class Marks : public Student
{
protected:
    vector<int> courseMarks;

public:
    Marks(string name, int rollNo, string department, vector<int> marks)
        : Student(name, rollNo, department), courseMarks(marks) {}

    void displayMarks()
    {
        cout << "Marks Obtained in Courses: ";
        for (int mark : courseMarks)
        {
            cout << mark << " ";
        }
        cout << endl;
    }

    vector<int> getMarks() { return courseMarks; }
};

class Result : public Marks
{
public:
    Result(string name, int rollNo, string department, vector<int> marks)
        : Marks(name, rollNo, department, marks) {}

    void displayResult()
    {
        int total = 0;
        for (int mark : courseMarks)
        {
            total += mark;
        }
        double average = static_cast<double>(total) / courseMarks.size();

        cout << "Total Marks: " << total << endl;
        cout << "Average Marks: " << average << endl;
    }
};

int main()
{
    vector<int> marks = {85, 90, 8, 88, 92};
    Result student("Izaan Khan", 994, "CS", marks);

    student.displayStudentInfo();
    student.displayMarks();
    student.displayResult();

    return 0;
}
