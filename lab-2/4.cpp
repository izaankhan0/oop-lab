#include <iostream>
#include <string>
using namespace std;

struct StaffMembers {
    int StaffID;
    string StaffFullName;
    double PayScale;
};

struct Enterprise {
    string EnterpriseTitle;
    string EnterpriseCode;
    StaffMembers Staff;
};



int main(int paramCount, char* paramValues[]) {
    if (paramCount < 7) {
        cout << "Entered Information is Incomplete" << endl;
        cout << "Kindly provide the required details:" << endl;
        cout << "1. Title" << endl;
        cout << "2. Code" << endl;
        cout << "3. Staff ID" << endl;
        cout << "4. Staff First Name" << endl;
        cout << "5. Staff Last Name" << endl;
        cout << "6. Staff Pay " << endl;
        return 0;
    }



    Enterprise Biz;
    Biz.EnterpriseTitle = paramValues[1];
    Biz.EnterpriseCode = paramValues[2];
    Biz.Staff.StaffID = stoi(paramValues[3]);
    string FirstName = paramValues[4];
    string LastName = paramValues[5];
    Biz.Staff.StaffFullName = FirstName + " " + LastName;
    Biz.Staff.PayScale = stoi(paramValues[6]);

    cout << "Total Size of Primary Structure [Enterprise]: " << sizeof(Enterprise) << endl;
    cout << "Title: " << Biz.EnterpriseTitle << endl;
    cout << "Code: " << Biz.EnterpriseCode << endl;
    cout << "Staff Identifier: " << Biz.Staff.StaffID << endl;
    cout << "Staff Full Name: " << Biz.Staff.StaffFullName << endl;
    cout << "Staff PayScale: " << Biz.Staff.PayScale << endl;
    return 0;
}
