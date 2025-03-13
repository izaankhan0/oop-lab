#include<iostream>
#include<vector>
using namespace std;

class bankAccount{
    protected:
        string accountNumber;
        double balance;
    public:

        bankAccount(string accountNumber):accountNumber(accountNumber){}
        bankAccount(string accountNumber, double balance):accountNumber(accountNumber), balance(balance){}

        virtual double setBalance(double balance){this->balance = balance; }
        string setAccountNumber(string accountNumber){this->accountNumber = accountNumber; }

        virtual double getBalance(){ return balance; }
        string getAccountNumber(){ return accountNumber; }
        virtual void display(){
            cout << "Account Number: " << accountNumber << endl;
            cout << "Balance: $" << balance << endl;
        }

        virtual void deposit(double amount){ 
            balance += amount;
            cout << "$" << amount << " deposited successfully!" << endl;
            cout << "Remaining Balance: $" << balance << endl;
        }
        virtual void withdraw(double amount){ 
            if(balance >= amount){
                balance -= amount;
                cout << "$" << amount << " withdrawn successfully!" << endl;
                cout << "Remaining Balance: $" << balance << endl;
            }else{
                cout << "Cannot withdraw, insufficient funds" << endl;
            }
        }

        virtual ~bankAccount(){}
};

class savingsAccount: public bankAccount{
    public:
        savingsAccount(string accountNumber, double balance):bankAccount(accountNumber, balance){}
        void applyRoyalty(double rate){ balance += balance * rate; }
        virtual ~savingsAccount(){}
};

class checkingAccount: public bankAccount{
    double overdraftLimit;
    public:
        checkingAccount(string accountNumber, double balance, double overdraftLimit):overdraftLimit(overdraftLimit), bankAccount(accountNumber, balance){}

        virtual void withdraw(double amount){
            if(((balance+overdraftLimit)-amount) >=0 ){
                balance -= amount;
                cout << "$" << amount << " withdrawn successfully!" << endl;
            }else{
                cout << "Warning! $" << amount << " exceeds overDraft limit: $" << overdraftLimit << endl;
            }
        }

        virtual ~checkingAccount(){}
        
};

class businessAccount: public bankAccount{
    int taxRate;
    public:
        businessAccount(string accountNumber, double balance, double taxRate):bankAccount(accountNumber, balance), taxRate(taxRate){}

        virtual void deposit(double amount){
            balance += taxRate * amount;
            cout << "$" << amount * taxRate << " deposited successfully!" << endl;
            cout << "Remaining Balance: $" << balance << endl;
        }

        virtual ~businessAccount(){}

};

class User: public bankAccount{
    public:
        User(string accountNumber): bankAccount(accountNumber){}
};

class Customer: public User{
    public:
        Customer(string accountNumber):User(accountNumber){}
        virtual void display(bankAccount *bank){
            bank->display();
            cout << "Customer can deposit & withdraw from their own account" << endl;
        }
        ~Customer(){}
};
    
class Employee: public User{
    public:
    Employee(string accountNumber):User(accountNumber){}
};

class Teller: public Employee{
    public:
    Teller(string accountNumber):Employee(accountNumber){}
    virtual void display(bankAccount *bank){
        bank->display();
        cout << "Teller can deposit, withdraw & freeze accounts" << endl;
    }
};

class Manager: public Employee{
    public:
    Manager(string accountNumber):Employee(accountNumber){}
    virtual void display(bankAccount *bank){
        bank->display();
        cout << "Manager can deposit, withdraw, freeze accounts & adjusted account limits" << endl;
    }
};

int main(){

    vector<bankAccount*> accounts;
    vector<User*> users;

    accounts.push_back(new savingsAccount("0001", 99.99));
    accounts.push_back(new checkingAccount("0002", 199.99, 29.99));
    accounts.push_back(new businessAccount("0003", 299.99, 5));

    for(int i = 0; i < accounts.size(); i++){

        accounts.at(i)->display();

    }

    users.push_back(new Customer("0994"));
    users.push_back(new Teller("0999"));
    users.push_back(new Manager("0973"));

    for (int i = 0; i < users.size(); i++)
    {
        users.at(i)->deposit((i + 1) * 100);
        users.at(i)->display();
    }
    

    return 0;
}