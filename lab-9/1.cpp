#include <iostream>
#include <string>

using namespace std;

// Account class
class Account {
private:
    double currentBalance;
    double todayDepositSum;
    double todayWithdrawSum;
    static const double MAX_DAILY_DEPOSIT_LIMIT;
    static const double MAX_DAILY_WITHDRAW_LIMIT;

public:
    Account() {
        currentBalance = 0.0;
        todayDepositSum = 0.0;
        todayWithdrawSum = 0.0;
    }

    bool addFunds(double cashIn) {
        if (cashIn <= 0) {
            cout << "Can't deposit non-positive amount." << endl;
            return false;
        }
        if (todayDepositSum + cashIn > MAX_DAILY_DEPOSIT_LIMIT) {
            cout << "Deposit blocked: over daily deposit cap." << endl;
            return false;
        }

        currentBalance += cashIn;
        todayDepositSum += cashIn;
        cout << "Added $" << cashIn << " | Balance is now: $" << currentBalance << endl;
        return true;
    }

    bool removeFunds(double cashOut) {
        if (cashOut <= 0) {
            cout << "Can't withdraw non-positive amount." << endl;
            return false;
        }
        if (cashOut > currentBalance) {
            cout << "Withdrawal denied: not enough funds." << endl;
            return false;
        }
        if (todayWithdrawSum + cashOut > MAX_DAILY_WITHDRAW_LIMIT) {
            cout << "Withdrawal denied: daily limit reached." << endl;
            return false;
        }

        currentBalance -= cashOut;
        todayWithdrawSum += cashOut;
        cout << "Removed $" << cashOut << " | Balance now: $" << currentBalance << endl;
        return true;
    }

    double checkBalance() const {
        return currentBalance;
    }

    void clearDailyLimits() {
        todayDepositSum = 0.0;
        todayWithdrawSum = 0.0;
    }
};

// Static constants definition
const double Account::MAX_DAILY_DEPOSIT_LIMIT = 1000.0;
const double Account::MAX_DAILY_WITHDRAW_LIMIT = 500.0;

// Client class
class Client {
private:
    string id;
    string fullName;
    Account bankAccount;

public:
    Client(string userID, string name) {
        id = userID;
        fullName = name;
    }

    void depositCash(double amount) {
        cout << "[" << fullName << "] Depositing $" << amount << endl;
        bankAccount.addFunds(amount);
    }

    void withdrawCash(double amount) {
        cout << "[" << fullName << "] Withdrawing $" << amount << endl;
        bankAccount.removeFunds(amount);
    }

    void displayBalance() const {
        cout << "[" << fullName << "] Balance: $" << bankAccount.checkBalance() << endl;
    }

    void resetDayLimits() {
        bankAccount.clearDailyLimits();
    }
};

int main() {
    Client c1("ACC101", "Zayan");
    Client c2("ACC102", "Ayaan");

    cout << "\n========== Zayan's Transactions ==========\n";
    c1.depositCash(300);
    c1.withdrawCash(100);
    c1.displayBalance();

    cout << "\n--- Testing Daily Limits ---\n";
    c1.depositCash(1800);
    c1.withdrawCash(1450);
    c1.resetDayLimits();
    c1.withdrawCash(1450);

    cout << "\n========== Ayaan's Transactions ==========\n\n";

    c2.depositCash(2000);
    c2.withdrawCash(500);
    c2.displayBalance();

    cout << "\n==========================================\n";
    return 0;
}
