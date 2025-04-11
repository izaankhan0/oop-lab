#include<iostream>
using namespace std;

class Wallet{
    double balance;
    double limit;
    public:
        Wallet(){}
        Wallet(double limit):limit(limit){}
        void deposit(double amount){
            if(amount < 0){cout << "Only POsitive Values allowed" << endl;return;}
            if (amount <= limit)
            {
                balance += amount;
                cout << "amount deposited" << endl;
            }else{
                cout << "amount exceeds daily limit: $"<<limit << endl;
            }
            
        }
        double withdraw(double amount){
            if(amount < 0){cout << "Only POsitive Values allowed" << endl;return;}
            if (amount <= limit)
            {
                balance += amount;
                cout << "amount withdrawn" << endl;
                return balance;
            }else{
                cout << "amount exceeds daily limit: $"<<limit << endl;
                return balance;
            }
        }
};

class User{
    
};


int main(){



    return 0;
}