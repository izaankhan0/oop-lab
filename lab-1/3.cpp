#include<iostream>
using namespace std;

int main(){
    string id;
    string name;
    int units;
    float charge;
    float total;
    float bill_extra;
    float bill_total;

    cin >> id;
    cin >> name;
    cin >> units;

    if (units > 0 && units <= 199)
    {
        charge = 16.2;
    }
    if (units >= 200 && units < 300)
    {
        charge = 20.1;
    }
    if (units >= 300 && units < 500)
    {
        charge = 27.1;
    }
    if (units >= 500)
    {
        charge = 35.9;
    }
    total = charge * units;

    if (total > 18000)
    {
        bill_extra = total * 0.15;
        bill_total = total + bill_extra;
    } else
    {
        bill_total = total;
    }

    cout << "Customer ID: " << id << endl << "Customer Name: " << name << endl << "Units Consumed: " << units << endl << "Amount Charges @Rs." << charge << " per unit: " << total << endl << "Surcharge Amount: " << bill_extra << endl << "Net Amount Paid by the Customer: " << bill_total << endl;
    
    


    return 0;
}