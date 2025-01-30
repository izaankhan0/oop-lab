#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main() {
    cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
    
    string name;
    int adult_tickets, child_tickets;
    float adult_price, child_price, charity, total_tickets;

    cout << "Enter Movie Name: ";
    getline(cin, name); 

    cout << "Enter Adult Ticket Price: ";
    cin >> adult_price;

    cout << "Enter Adult Tickets Sold: ";
    cin >> adult_tickets;

    cout << "Enter Child Ticket Price: ";
    cin >> child_price;

    cout << "Enter Child Tickets Sold: ";
    cin >> child_tickets; 

    cout << "Enter Charity %: ";
    cin >> charity;

    total_tickets = adult_tickets + child_tickets;
    float gross_amount = (adult_price * adult_tickets) + (child_price * child_tickets);
    float amount_donated = gross_amount * (charity / 100);
    float net_sale = gross_amount - amount_donated;

    cout << "Movie Name: " << name << endl;
    cout << "Number of Tickets Sold: " << total_tickets << endl;
    printf("Gross Amount: $ %.2f\n", gross_amount);
    printf("Percentage of Gross Amount Donated: %.2f%%\n", charity);
    printf("Amount Donated: $ %.2f\n", amount_donated);
    printf("Net Sale: $ %.2f\n", net_sale);

    return 0;
}
